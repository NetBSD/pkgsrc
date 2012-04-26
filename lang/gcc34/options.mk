# $NetBSD: options.mk,v 1.2 2012/04/26 13:27:43 hans Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gcc34
PKG_SUPPORTED_OPTIONS=	nls gcc-inplace-math gcc-c++ gcc-fortran gcc-java gcc-objc gcc-ada
PKG_SUGGESTED_OPTIONS=	gcc-inplace-math gcc-c++ gcc-fortran gcc-java gcc-objc
.if ${OPSYS} == "NetBSD"
PKG_SUGGESTED_OPTIONS+=	nls
.elif ${OPSYS} == "SunOS"
PKG_SUGGESTED_OPTIONS+=	gcc-inplace-math
.endif

PKG_OPTIONS_LEGACY_VARS+=	BUILD_CXX:gcc-c++
PKG_OPTIONS_LEGACY_VARS+=	BUILD_F77:gcc-fortran
PKG_OPTIONS_LEGACY_VARS+=	BUILD_JAVA:gcc-java
PKG_OPTIONS_LEGACY_VARS+=	BUILD_OBJC:gcc-objc

.include "../../mk/bsd.options.mk"

###
### Build math libraries in place
###
.if !empty(PKG_OPTIONS:Mgcc-fortran)
.  if !empty(PKG_OPTIONS:Mgcc-inplace-math)
.  include "../../devel/gmp/inplace.mk"
.  else
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
.  include "../../devel/gmp/buildlink3.mk"
.  endif
.endif

###
### Native Language Support
###
.if !empty(PKG_OPTIONS:Mnls)
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
MAKE_ENV+=		ICONVPREFIX=${BUILDLINK_PREFIX.iconv}
USE_TOOLS+=		msgfmt
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

###
### Optional languages
### Ada could be added although there is a bootstrapping issue.  See
### ../gcc34-ada for guidance
###

LANGS=			c

.if !empty(PKG_OPTIONS:Mgcc-c++)
LANGS+=			c++
CONFIGURE_ARGS+=	--enable-__cxa_atexit
.endif

.if !empty(PKG_OPTIONS:Mgcc-fortran)
USE_TOOLS+=             chmod
MAKE_ENV+=              ac_cv_path_ac_cv_prog_chmod=${TOOLS_CHMOD:Q}
LANGS+=			f77
.endif

.if !empty(PKG_OPTIONS:Mgcc-java)
LANGS+=			java
REPLACE_AWK+=		libjava/addr2name.awk

USE_TOOLS+=		awk:run unzip zip:run
CONFIGURE_ARGS+=	--with-system-zlib

.include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgcc-objc)
LANGS+=			objc
.endif

.if !empty(PKG_OPTIONS:Mgcc-ada)
PTHREAD_OPTS+=          require native
LANGS+=		ada

# Ada bootstrap compiler section
# An Ada compiler is required to build the Ada compiler. You
# may specify:
#USE_GCC34ADA	=# Define to use gcc-3.4.x-ada
# Or, you may specify the path of any gcc/gnat Ada compiler
# by providing the full path of the compiler (example) below:
ALT_GCC=	/usr/pkg/bin/gnatgcc
.  if defined(ALT_GCC)
.     if exists(${ALT_GCC})
ALT_GCC_RTS!=	${ALT_GCC} --print-file-name=adalib
.	if !empty(ALT_GCC_RTS)
RALT_GCC_RTS=	${ALT_GCC_RTS:S%${LOCALBASE}%%:S%/%%}
.	else
PKG_SKIP_REASON+=	"${ALT_GCC} does not appear to be an Ada compiler"
.	endif
.     else
PKG_SKIP_REASON+=	"Missing bootstrap Ada compiler"
.     endif
.  endif
.  if !defined(USE_GCC34ADA) && !defined(ALT_GCC)
PKG_SKIP_REASON+=	"An Ada bootstrap compiler must be specified to build Ada"
.  endif

.  if defined(USE_GCC34ADA)
BUILDLINK_DEPMETHOD.gcc34-ada=build
.include "../../lang/gcc34-ada/buildlink3.mk"

post-patch:
	(cd ${FILESDIR}; \
		${CP} adasignal.c ${WRKSRC}/gcc/ada; \
		${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
		${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
		for i in *.adb *.ads ; do \
			${CP} $$i ${WRKSRC}/gcc/ada; \
		done )

# Overide compiler.mk setup to use gcc-3.4.x-ada
pre-configure:
.include "../../lang/gcc34-ada/preconfigure.mk"
.  elif defined(ALT_GCC)
pre-configure:
	(${TEST} -d ${WRKDIR}/.gcc/bin/ || ${MKDIR} ${WRKDIR}/.gcc/bin/)
	(cd ${WRKDIR}/.buildlink && ${MKDIR} ${RALT_GCC_RTS} && \
	cd ${RALT_GCC_RTS} && ${LN} -sf ${ALT_GCC_RTS}/libgnat.a .)
	(cd ${ALT_GCC:H} && \
		bin_files=`${FIND} . -type f \( -perm -0100 \) -print` && \
	cd ${WRKDIR}/.gcc/bin/ && \
	for filename in ${ALT_GCC:T} $${bin_files} ; do \
		${ECHO} '#!${TOOLS_SHELL}' > $${filename}; \
		${ECHO} -n "exec ${ALT_GCC:H}/$${filename} " >>$${filename}; \
		${ECHO} '"$$@"' >>$${filename}; \
		${CHMOD} +x $${filename}; \
	done )
.  endif
.endif
