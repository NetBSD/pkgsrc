#	$NetBSD: bsd.pkg.mk,v 1.874 2001/12/04 06:14:57 jlam Exp $
#
# This file is in the public domain.
#
# This file is derived from bsd.port.mk - 940820 Jordan K. Hubbard.
#
# Please see the NetBSD packages(7) manual page for details on the
# that variables used in this make file template.

# Default sequence for "all" is:  fetch checksum extract patch configure build
#
# Please read the comments in the targets section below, you
# should be able to use the pre-* or post-* targets/scripts
# (which are available for every stage except checksum) or
# override the do-* targets to do pretty much anything you want.
#
# NEVER override the "regular" targets unless you want to open
# a major can of worms.

##### Include any preferences, if not already included, and common definitions
.include "../../mk/bsd.prefs.mk"

##### Pass information about desired toolchain to package build.
.if defined(USETOOLS)
MAKE_ENV+=	USETOOLS="${USETOOLS}"
.endif

##### Build crypto packages by default.
MKCRYPTO?=		yes

CLEANDEPENDS?=		NO
DEINSTALLDEPENDS?=	NO	# add -R to pkg_delete
REINSTALL?=		NO	# reinstall upon update
CHECK_SHLIBS?=		YES	# run check-shlibs after install
SHLIB_HANDLING?=	YES	# do automatic shared lib handling
NOCLEAN?=		NO	# don't clean up after update

PKGSRCDIR?=		${.CURDIR:C|/[^/]*/[^/]*$||}
PKGPATH?=		${.CURDIR:C|.*/([^/]*/[^/]*)$|\1|}
PKGBASE?=		${PKGNAME:C/-[^-]*$//}
PKGVERSION?=		${PKGNAME:C/^.*-//}
PKGWILDCARD?=		${PKGBASE}-[0-9]*

DISTDIR?=		${PKGSRCDIR}/distfiles
_DISTDIR?=		${DISTDIR}/${DIST_SUBDIR}
PACKAGES?=		${PKGSRCDIR}/packages
TEMPLATES?=		${PKGSRCDIR}/templates

PATCHDIR?=		${.CURDIR}/patches
SCRIPTDIR?=		${.CURDIR}/scripts
FILESDIR?=		${.CURDIR}/files
PKGDIR?=		${.CURDIR}

.if defined(USE_JAVA)
BUILD_DEFS+=		PKG_JVM JAVA_HOME
.  if !defined(PKG_JVM)
.    if ${MACHINE_PLATFORM:MNetBSD-*-i386} != "" || \
       ${MACHINE_PLATFORM:MLinux-*-i386} != ""
PKG_JVM?=		jdk
.    elif ${MACHINE_PLATFORM:MNetBSD-*-powerpc} != ""
PKG_JVM?=		blackdown-jdk13
.    else
PKG_JVM?=		kaffe
.    endif
.  endif
.  if ${PKG_JVM} == "jdk"
DEPENDS+=		jdk-*:../../lang/jdk
.    if defined(JDK_HOME)
JAVA_HOME?=		${JDK_HOME}
.    else
JAVA_HOME?=		${LOCALBASE}/java
.    endif
.  elif ${PKG_JVM} == "sun-jdk"
BUILD_DEPENDS+=		sun-jdk-*:../../lang/sun-jdk13
DEPENDS+=		sun-jre-*:../../lang/sun-jre13

JAVA_HOME?=		${LOCALBASE}/java
.  elif ${PKG_JVM} == "blackdown-jdk13"
DEPENDS+=		blackdown-jdk-*:../../lang/blackdown-jdk13
JAVA_HOME?=		${LOCALBASE}/java
.  elif ${PKG_JVM} == "kaffe"
DEPENDS+=		kaffe-[0-9]*:../../lang/kaffe
JAVA_HOME?=		${LOCALBASE}/kaffe
.  endif
.  if exists(${JAVA_HOME}/lib/classes.zip:)
CLASSPATH?=		${JAVA_HOME}/lib/classes.zip:.

MAKE_ENV+=		CLASSPATH=${CLASSPATH}
CONFIGURE_ENV+=		CLASSPATH=${CLASSPATH}
SCRIPTS_ENV+=		CLASSPATH=${CLASSPATH}
.  endif
PATH:=			${PATH}:${JAVA_HOME}/bin
MAKE_ENV+=		JAVA_HOME=${JAVA_HOME}
CONFIGURE_ENV+=		JAVA_HOME=${JAVA_HOME}
SCRIPTS_ENV+=		JAVA_HOME=${JAVA_HOME}
.endif

# Set X11PREFIX to reflect the install directory of X11 packages.
# Set XMKMF_CMD properly if xpkgwedge is installed.
#
# The check for the existence of ${X11BASE}/lib/X11/config/xpkgwedge.def
# is to catch users of xpkgwedge<1.0.
#
XMKMF?=			${XMKMF_CMD} ${XMKMF_FLAGS} -a
XMKMF_FLAGS?=		# empty
.if exists(${LOCALBASE}/lib/X11/config/xpkgwedge.def) || \
    exists(${X11BASE}/lib/X11/config/xpkgwedge.def)
X11PREFIX=		${LOCALBASE}
XMKMF_CMD?=		${X11PREFIX}/bin/pkgxmkmf
.else
X11PREFIX=		${X11BASE}
XMKMF_CMD?=		${X11PREFIX}/bin/xmkmf
.endif

# Set the default BUILDLINK_DIR and BUILDLINK_X11_DIR so that if no
# buildlink.mk files are included, then they still points to a where headers
# and libraries for installed packages and X11R6 may be found, respectively.
#
BUILDLINK_DIR?=		${LOCALBASE}
BUILDLINK_X11_DIR?=	${X11BASE}

.if defined(USE_IMAKE) || defined(USE_X11BASE)
.  if exists(${LOCALBASE}/lib/X11/config/xpkgwedge.def) || \
      exists(${X11BASE}/lib/X11/config/xpkgwedge.def)
BUILD_DEPENDS+=		xpkgwedge>=1.5:../../pkgtools/xpkgwedge
.  endif
PREFIX=			${X11PREFIX}
.elif defined(USE_CROSSBASE)
PREFIX=			${CROSSBASE}
NO_MTREE=		yes
.else
PREFIX=			${LOCALBASE}
.endif

# We need to make sure the buildlink-x11 package is not installed since it
# currently breaks builds that use imake.
#
.if defined(USE_IMAKE) && !defined(USE_BUILDLINK_X11)
.  if exists(${LOCALBASE}/lib/X11/config/buildlinkX11.def) || \
      exists(${X11BASE}/lib/X11/config/buildlinkX11.def)
IGNORE+= "${PKGNAME} uses imake, but the buildlink-x11 package was found." \
	 "    Please deinstall it (pkg_delete buildlink-x11)."
.  endif
.endif	# USE_IMAKE && !USE_BUILDLINK_X11

.if defined(USE_GMAKE)
BUILD_DEPENDS+=		gmake>=3.78:../../devel/gmake
MAKE_PROGRAM=		${GMAKE}
GMAKE?=			gmake
.else
.  if defined(USE_IMAKE)
MAKE_PROGRAM=		${_IMAKE_MAKE}
.  else
MAKE_PROGRAM=		${MAKE}
.  endif
.endif
CONFIGURE_ENV+=		MAKE="${MAKE_PROGRAM}"

.if defined(USE_KERBEROS)
RESTRICTED?=		uses Kerberos encryption code
BUILD_DEFS+=		KERBEROS
.endif

PERL5?=			${LOCALBASE}/bin/perl
PERL5_REQD?=		5.0
.if defined(USE_PERL5)
DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5
.  if exists(${PERL5})
.    if exists(${LOCALBASE}/share/mk/bsd.perl.mk)
.      include "${LOCALBASE}/share/mk/bsd.perl.mk"
.    elif !defined(PERL5_SITELIB) || !defined(PERL5_SITEARCH) || !defined(PERL5_ARCHLIB)
PERL5_SITELIB!=		eval `${PERL5} -V:installsitelib 2>/dev/null`; \
			${ECHO} $${installsitelib}
PERL5_SITEARCH!=	eval `${PERL5} -V:installsitearch 2>/dev/null`; \
			${ECHO} $${installsitearch}
PERL5_ARCHLIB!=		eval `${PERL5} -V:installarchlib 2>/dev/null`; \
			${ECHO} $${installarchlib}
MAKEFLAGS+=		PERL5_SITELIB=${PERL5_SITELIB}
MAKEFLAGS+=		PERL5_SITEARCH=${PERL5_SITEARCH}
MAKEFLAGS+=		PERL5_ARCHLIB=${PERL5_ARCHLIB}
.    endif # !exists(bsd.perl.mk) && !defined(PERL5_*)
.  endif # exists($PERL5)
.endif # USE_PERL5

.if defined(USE_PYTHON)
PYTHON?=		${LOCALBASE}/bin/python
DEPENDS+=		python>=1.6:../../lang/python
.  if exists(${PYTHON})
BUILD_DEPENDS+=		python-mk-*:../../pkgtools/python-mk
.    if exists(${LOCALBASE}/share/mk/bsd.python.mk)
.      include "${LOCALBASE}/share/mk/bsd.python.mk"
.    endif
.  endif
.endif

.if defined(USE_FORTRAN)
.  if !exists(/usr/bin/f77)
PKG_FC?=		f2c-f77
.  endif
# it is anticipated that once /usr/bin/f77 is more stable that the following
# default will be changed to f77.  However, in the case where there is no
# /usr/bin/f77, the default will remain as f2c-f77.
PKG_FC?=		f2c-f77
.  if  (${PKG_FC} == "f2c-f77")
# this is a DEPENDS not BUILD_DEPENDS because of the
# shared Fortran libs
.    if defined(USE_BUILDLINK_ONLY)
.      include "../../lang/f2c/buildlink.mk"
.    else
DEPENDS+=       f2c>=20001205nb3:../../lang/f2c
.    endif
.  endif
FC=             ${PKG_FC}
F77=            ${PKG_FC}
CONFIGURE_ENV+=	F77="${F77}"
CONFIGURE_ENV+=	FFLAGS="${FFLAGS}"
MAKE_ENV+=	F77="${F77}"
MAKE_ENV+=	FC="${FC}"
.endif

.if defined(INFO_FILES)
USE_GTEXINFO=		yes
.endif

.if ((defined(NEED_NCURSES)) && (${NEED_NCURSES} == YES))
DEPENDS+=		ncurses>=5.0:../../devel/ncurses
.endif

.if defined(USE_GTEXINFO) && !exists(/usr/bin/install-info)
DEPENDS+=		gtexinfo-3.12:../../devel/gtexinfo
.endif

# -lintl in CONFIGURE_ENV is to workaround broken gettext.m4
# (gettext.m4 does not add -lintl where it should, and fails to detect
# if libintl.a is genuine GNU gettext or not).
.if ${_DO_LIBINTL_CHECKS} == "yes"
.  if defined(USE_LIBINTL)
.    if exists(/usr/include/libintl.h)
.      if defined(GNU_CONFIGURE)
LIBS+=		-lintl
.      endif
.    else
DEPENDS+=	gettext-lib>=0.10.35nb1:../../devel/gettext-lib
.      if defined(GNU_CONFIGURE)
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl
.      endif
.    endif
.  endif
.endif

# If GNU_CONFIGURE is defined, then pass LIBS to the GNU configure script.
.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=	LIBS="${LIBS}"
.endif

LIBTOOL_REQD=		1.4.20010614nb4
.if defined(USE_LIBTOOL)
LIBTOOL=		${LOCALBASE}/bin/libtool
.  if defined(USE_LTDL)
DEPENDS+=		libtool>=${LIBTOOL_REQD}:../../devel/libtool
.  else
BUILD_DEPENDS+=		libtool-base>=${LIBTOOL_REQD}:../../devel/libtool-base
.  endif
CONFIGURE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=		LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
.endif

.if defined(USE_SSL)
.  if exists(/usr/include/openssl/ssl.h)
SSLBASE=	/usr
SSLCERTS=	/etc/openssl/certs
.  else
DEPENDS+=	openssl-0.9.[56]*:../../security/openssl
SSLBASE=	${LOCALBASE}
SSLCERTS=	${SSLBASE}/certs
.  endif
BUILD_DEFS+=	SSLBASE
.endif

.if defined(USE_XAW)
.  if defined(XAW_TYPE)
.    if ${XAW_TYPE} == "xpm"
DEPENDS+=		Xaw-Xpm-1.1:../../x11/Xaw-Xpm
.    elif ${XAW_TYPE} == "3d"
DEPENDS+=		Xaw3d-1.5:../../x11/Xaw3d
.    endif
.  endif
.endif

.if defined(BUILD_USES_MSGFMT) && !exists(/usr/bin/msgfmt)
BUILD_DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
.endif

.if defined(BUILD_USES_GETTEXT_M4)
BUILD_DEPENDS+=		{gettext-0.10.35nb1,gettext-m4-*}:../../devel/gettext-m4
.endif

# Don't change these!!!  These names are built into the _TARGET_USE macro,
# there is no way to refer to them cleanly from within the macro AFAIK.
EXTRACT_COOKIE=		${WRKDIR}/.extract_done
CONFIGURE_COOKIE=	${WRKDIR}/.configure_done
INSTALL_COOKIE=		${WRKDIR}/.install_done
BUILD_COOKIE=		${WRKDIR}/.build_done
PATCH_COOKIE=		${WRKDIR}/.patch_done
PACKAGE_COOKIE=		${WRKDIR}/.package_done

# New message digest defs
DIGEST_ALGORITHM?=	SHA1

# Miscellaneous overridable commands:
SHCOMMENT?=		${ECHO_MSG} >/dev/null '***'

DISTINFO_FILE?=		${.CURDIR}/distinfo

.if exists(/usr/bin/m4)
M4?=			/usr/bin/m4
.endif

.if !defined(X11_BUILDLINK_MK)
.  if defined(USE_X11BASE) || defined(USE_X11)
LDFLAGS+=		-Wl,-R${X11BASE}/lib
LDFLAGS+=		-L${X11BASE}/lib
.  endif
.endif
.if ${_USE_RPATH} == "yes"
LDFLAGS+=		-Wl,-R${LOCALBASE}/lib
.endif
.if !defined(USE_BUILDLINK_ONLY)
LDFLAGS+=		-L${LOCALBASE}/lib
.endif
MAKE_ENV+=		LDFLAGS="${LDFLAGS}"
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}" M4="${M4}" YACC="${YACC}"

MAKE_FLAGS?=
MAKEFILE?=		Makefile
MAKE_ENV+=		PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"

.if exists(${ZOULARISBASE}/bin/ftp)			# Zoularis
FETCH_CMD?=		${ZOULARISBASE}/bin/ftp
.else
FETCH_CMD?=		/usr/bin/ftp
.endif

TOUCH_FLAGS?=		-f

PATCH_STRIP?=		-p0
PATCH_DIST_STRIP?=	-p0
.if defined(PATCH_DEBUG) || defined(PKG_VERBOSE)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS?=		-d ${WRKSRC} -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-d ${WRKSRC} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS?=		-d ${WRKSRC} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-d ${WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
.if defined(BATCH)
PATCH_ARGS+=		--batch
PATCH_DIST_ARGS+=	--batch
.endif
PATCH_ARGS+=		-V simple ${_PATCH_BACKUP_ARG} .orig
PATCH_FUZZ_FACTOR?=	-F0			# Default to zero fuzz

# If the distfile has a tar.bz2 suffix, use bzcat in preference to gzcat,
# pulling in the "bzip2" package if necessary. [Note: this is only for
# the benefit of pre 1.5 NetBSD systems. "gzcat" on newer systems happily
# decodes bzip2.] Do likewise for ".zip" and ".lha" distfiles.
EXTRACT_SUFX?=		.tar.gz
.if ${EXTRACT_SUFX} == ".tar.bz2"
.  if exists(/usr/bin/bzcat)
BZCAT=			/usr/bin/bzcat <
.  else
BZCAT=			${LOCALBASE}/bin/bzcat
BUILD_DEPENDS+=		bzip2>=0.9.0b:../../archivers/bzip2
.  endif # !exists bzcat
DECOMPRESS_CMD?=	${BZCAT}
.elif ${EXTRACT_SUFX} == ".tar"
DECOMPRESS_CMD?=	${CAT}
.elif ${EXTRACT_SUFX} == ".zip"
BUILD_DEPENDS+=		unzip-*:../../archivers/unzip
EXTRACT_CMD?=		unzip -Laq ${DOWNLOADED_DISTFILE}
.elif ${EXTRACT_SUFX} == ".lzh" || ${EXTRACT_SUFX} == ".lha"
BUILD_DEPENDS+=		lha-114f:../../archivers/lha
EXTRACT_CMD?=		lha xq ${DOWNLOADED_DISTFILE}
.else
DECOMPRESS_CMD?=	${GZCAT}
.endif

# Also need bzip2 for PATCHFILES with .bz2 suffix.
.if defined(PATCHFILES)
.  if ${PATCHFILES:E} == "bz2" && ${EXTRACT_SUFX} != ".tar.bz2"
.    if exists(/usr/bin/bzcat)
BZCAT=			/usr/bin/bzcat
.    else
BZCAT=			${LOCALBASE}/bin/bzcat
BUILD_DEPENDS+=		bzip2>=0.9.0b:../../archivers/bzip2
.    endif # !exists bzcat
.  endif
.endif # defined(PATCHFILES)

# If this is empty, then everything gets extracted.
EXTRACT_ELEMENTS?=	

# If EXTRACT_USING_PAX is defined, use pax in preference to (GNU) tar,
# and append 2 tar blocks of zero bytes on the end, in case the archive
# was written with a buggy version of GNU tar.
.if defined(EXTRACT_USING_PAX)
EXTRACT_CMD?=		{ ${DECOMPRESS_CMD} ${DOWNLOADED_DISTFILE} ; dd if=/dev/zero bs=10k count=2; } | ${PAX} -r ${EXTRACT_ELEMENTS}
.else
EXTRACT_CMD?=		${DECOMPRESS_CMD} ${DOWNLOADED_DISTFILE} | ${GTAR} -xf - ${EXTRACT_ELEMENTS}
.endif

# Figure out where the local mtree file is
.if !defined(MTREE_FILE)
.  if defined(USE_IMAKE) || defined(USE_X11BASE)
MTREE_FILE=	${PKGSRCDIR}/mk/${OPSYS}.x11.dist
.  else
MTREE_FILE=	${PKGSRCDIR}/mk/${OPSYS}.pkg.dist
.  endif
.endif # ! MTREE_FILE

MTREE_ARGS?=	-U -f ${MTREE_FILE} -d -e -p

# Debugging levels for this file, dependent on PKG_DEBUG_LEVEL definition
# 0 == normal, default, quiet operation
# 1 == all shell commands echoed before invocation
# 2 == shell "set -x" operation
PKG_DEBUG_LEVEL?=	0
_PKG_SILENT=		@
_PKG_DEBUG=		

.if ${PKG_DEBUG_LEVEL} > 0
_PKG_SILENT=	
.endif

.if ${PKG_DEBUG_LEVEL} > 1
_PKG_DEBUG=		set -x;
.endif

# If WRKOBJDIR is set, use that tree to build
.ifdef WRKOBJDIR
BUILD_DIR?=		${WRKOBJDIR}/${PKGPATH}
.else
BUILD_DIR?=		${.CURDIR}
.endif # WRKOBJDIR

# If OBJMACHINE is set, use ${MACHINE_ARCH} in the working directory name
.ifdef OBJMACHINE
WRKDIR_BASENAME?=	work.${MACHINE_ARCH}
.else
WRKDIR_BASENAME?=	work
.endif

WRKDIR?=		${BUILD_DIR}/${WRKDIR_BASENAME}
WRKSRC?=		${WRKDIR}/${DISTNAME}

.if defined(NO_WRKSUBDIR)
.BEGIN:
	@${ECHO_MSG} 'NO_WRKSUBDIR has been deprecated - please replace it with an explicit'
	@${ECHO_MSG} 'assignment of WRKSRC= $${WRKDIR}'
	@${FALSE}
.endif # NO_WRKSUBDIR

# A few aliases for *-install targets
INSTALL_PROGRAM?= \
	${INSTALL} ${COPY} ${STRIPFLAG} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT?= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_DATA?= \
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE}
INSTALL_MAN?= \
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m ${MANMODE}
INSTALL_PROGRAM_DIR?= \
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT_DIR?= \
	${INSTALL_PROGRAM_DIR}
INSTALL_DATA_DIR?= \
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${BINMODE}
INSTALL_MAN_DIR?= \
	${INSTALL} -d -o ${MANOWN} -g ${MANGRP} -m ${BINMODE}

INSTALL_MACROS=	BSD_INSTALL_PROGRAM="${INSTALL_PROGRAM}"		\
		BSD_INSTALL_SCRIPT="${INSTALL_SCRIPT}"			\
		BSD_INSTALL_DATA="${INSTALL_DATA}"			\
		BSD_INSTALL_MAN="${INSTALL_MAN}"			\
		BSD_INSTALL_PROGRAM_DIR="${INSTALL_PROGRAM_DIR}"	\
		BSD_INSTALL_SCRIPT_DIR="${INSTALL_SCRIPT_DIR}"		\
		BSD_INSTALL_DATA_DIR="${INSTALL_DATA_DIR}"		\
		BSD_INSTALL_MAN_DIR="${INSTALL_MAN_DIR}"
MAKE_ENV+=	${INSTALL_MACROS}
SCRIPTS_ENV+=	${INSTALL_MACROS}

# The user can override the NO_PACKAGE by specifying this from
# the make command line
.if defined(FORCE_PACKAGE)
.  undef NO_PACKAGE
.endif

.if !defined(COMMENT)
COMMENT!=	(${CAT} ${PKGDIR}/COMMENT || ${ECHO} -n "(no description)") 2>/dev/null
.endif

DESCR=			${WRKDIR}/.DESCR
.if !defined(DESCR_SRC)
DESCR_SRC?=		${PKGDIR}/DESCR
.endif
PLIST=			${WRKDIR}/.PLIST
.if !defined(PLIST_SRC)
PLIST_SRC?=		${PKGDIR}/PLIST
.endif
DLIST=			${WRKDIR}/.DLIST
DDIR=			${WRKDIR}/.DDIR


# Set PLIST_SUBST to substitute "${variable}" to "value" in PLIST
PLIST_SUBST+=	OPSYS=${OPSYS}						\
		OS_VERSION=${OS_VERSION}				\
		MACHINE_ARCH=${MACHINE_ARCH}				\
		MACHINE_GNU_ARCH=${MACHINE_GNU_ARCH}			\
		MACHINE_GNU_PLATFORM=${MACHINE_GNU_PLATFORM}		\
		LOWER_VENDOR=${LOWER_VENDOR}				\
		LOWER_OPSYS=${LOWER_OPSYS}				\
		PKGBASE=${PKGBASE}					\
		PKGNAME=${PKGNAME}					\
		PKGLOCALEDIR=${PKGLOCALEDIR}				\
		PKGVERSION=${PKGVERSION:C/nb[0-9]*$//}			\
		SVR4_PKGNAME=${SVR4_PKGNAME}				\
		CHGRP=${CHGRP:Q}					\
		CHMOD=${CHMOD:Q}					\
		CHOWN=${CHOWN:Q}					\
		MKDIR=${MKDIR:Q}					\
		RMDIR=${RMDIR:Q}					\
		TRUE=${TRUE:Q}
.if defined(PERL5_SITELIB)
PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SITELIB:S/^${LOCALBASE}\///}
.endif
.if defined(PERL5_SITEARCH)
PLIST_SUBST+=	PERL5_SITEARCH=${PERL5_SITEARCH:S/^${LOCALBASE}\///}
.endif
.if defined(PERL5_ARCHLIB)
PLIST_SUBST+=	PERL5_ARCHLIB=${PERL5_ARCHLIB:S/^${LOCALBASE}\///}
.endif

# Set INSTALL_FILE to be the name of any INSTALL file
.if !defined(INSTALL_FILE) && exists(${PKGDIR}/INSTALL)
INSTALL_FILE=		${PKGDIR}/INSTALL
.elif !defined(INSTALL_FILE) && exists(${.CURDIR}/INSTALL)
INSTALL_FILE=		${.CURDIR}/INSTALL
.endif

# Set DEINSTALL_FILE to be the name of any DEINSTALL file
.if !defined(DEINSTALL_FILE) && exists(${PKGDIR}/DEINSTALL)
DEINSTALL_FILE=		${PKGDIR}/DEINSTALL
.elif !defined(DEINSTALL_FILE) && exists(${.CURDIR}/DEINSTALL)
DEINSTALL_FILE=		${.CURDIR}/DEINSTALL
.endif

# If MESSAGE hasn't been defined, then set MESSAGE_SRC to be a space-separated
# list of files to be concatenated together to generate the MESSAGE file.
#
.if !defined(MESSAGE_SRC) && !defined(MESSAGE) && exists(${PKGDIR}/MESSAGE)
MESSAGE_SRC=		${PKGDIR}/MESSAGE
.elif !defined(MESSAGE_SRC) && !defined(MESSAGE) && exists(${.CURDIR}/MESSAGE)
MESSAGE_SRC=		${.CURDIR}/MESSAGE
.endif

.if defined(MESSAGE_SRC)
MESSAGE=		${WRKDIR}/.MESSAGE

# Set MESSAGE_SUBST to substitute "${variable}" to "value" in MESSAGE
MESSAGE_SUBST+=	PKGNAME=${PKGNAME}					\
		PREFIX=${PREFIX}					\
		LOCALBASE=${LOCALBASE}					\
		X11PREFIX=${X11PREFIX}					\
		X11BASE=${X11BASE}

MESSAGE_SUBST_SED=	${MESSAGE_SUBST:S/=/}!/:S/$/!g/:S/^/ -e s!\\\${/}
.endif

PKG_ADD?=	PKG_DBDIR=${PKG_DBDIR} ${PKG_TOOLS_BIN}/pkg_add
PKG_ADMIN?=	PKG_DBDIR=${PKG_DBDIR} ${PKG_TOOLS_BIN}/pkg_admin
PKG_CREATE?=	PKG_DBDIR=${PKG_DBDIR} ${PKG_TOOLS_BIN}/pkg_create
PKG_DELETE?=	PKG_DBDIR=${PKG_DBDIR} ${PKG_TOOLS_BIN}/pkg_delete
PKG_INFO?=	PKG_DBDIR=${PKG_DBDIR} ${PKG_TOOLS_BIN}/pkg_info

# Latest version of digest(1) required for pkgsrc
DIGEST_REQD=		20010302

uptodate-digest:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${DIGEST} -o ${DIGEST_VERSION} -lt ${DIGEST_REQD} ]; then \
		case ${PKGNAME} in					\
		digest-*)						\
			;;						\
		*)							\
			{ cd ${PKGSRCDIR}/pkgtools/digest;		\
			${MAKE} clean;					\
			if [ -f ${DIGEST} ]; then			\
				${MAKE} ${MAKEFLAGS} deinstall;		\
			fi;						\
			${MAKE} ${MAKEFLAGS} ${DEPENDS_TARGET};		\
			${MAKE} ${MAKEFLAGS} clean; } 			\
			;;						\
		esac							\
	fi

# Latest version of pkgtools required for this file.
PKGTOOLS_REQD=		20010306

# Check that we are using up-to-date pkg_* tools with this file.
.if defined(ZOULARIS_VERSION)
uptodate-pkgtools: uptodate-zoularis
.else
uptodate-pkgtools:
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ${PKGTOOLS_VERSION} -lt ${PKGTOOLS_REQD} ]; then		\
		case ${PKGNAME} in					\
		digest-*|pkg_install-*)					\
			;;						\
		*)							\
			${ECHO} "Your package tools need to be updated to ${PKGTOOLS_REQD:C|(....)(..)(..)|\1/\2/\3|} versions."; \
			${ECHO} "The installed package tools were last updated on ${PKGTOOLS_VERSION:C|(....)(..)(..)|\1/\2/\3|}."; \
			${ECHO} "Please \"make install\" in ../../pkgtools/pkg_install."; \
			${FALSE} ;;					\
		esac							\
	fi

# Latest version of Zoularis required for this file.
ZOULARIS_REQD=		20010323

# Check that we are using up-to-date Zoularis.
.if defined(ZOULARIS_VERSION)
uptodate-zoularis:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ${ZOULARIS_VERSION} -lt ${ZOULARIS_REQD} ]; then		\
		${ECHO} "Your Zoularis needs to be updated to the ${ZOULARIS_REQD:C|(....)(..)(..)|\1/\2/\3|} version."; \
		${ECHO} "The installed Zoularis was last updated on ${ZOULARIS_VERSION:C|(....)(..)(..)|\1/\2/\3|}."; \
		${FALSE};					\
	fi
.endif

# Files to create for versioning and build information
BUILD_VERSION_FILE=	${WRKDIR}/.build_version
BUILD_INFO_FILE=	${WRKDIR}/.build_info

# Files containing size of pkg w/o and w/ all required pkgs
SIZE_PKG_FILE=		${WRKDIR}/.SizePkg
SIZE_ALL_FILE=		${WRKDIR}/.SizeAll

.ifndef PKG_ARGS_COMMON
PKG_ARGS_COMMON=	-v -c -${COMMENT:Q}" " -d ${DESCR} -f ${PLIST}
PKG_ARGS_COMMON+=	-l -b ${BUILD_VERSION_FILE} -B ${BUILD_INFO_FILE}
PKG_ARGS_COMMON+=	-s ${SIZE_PKG_FILE} -S ${SIZE_ALL_FILE}
PKG_ARGS_COMMON+=	-P "`${MAKE} ${MAKEFLAGS} run-depends-list PACKAGE_DEPENDS_QUICK=true | ${SORT} -u`"
.  ifdef CONFLICTS
PKG_ARGS_COMMON+=	-C "${CONFLICTS}"
.  endif
.  ifdef INSTALL_FILE
PKG_ARGS_COMMON+=	-i ${INSTALL_FILE}
.  endif
.  ifdef DEINSTALL_FILE
PKG_ARGS_COMMON+=	-k ${DEINSTALL_FILE}
.  endif
.  ifdef MESSAGE
PKG_ARGS_COMMON+=	-D ${MESSAGE}
.  endif
.  ifndef NO_MTREE
PKG_ARGS_COMMON+=	-m ${MTREE_FILE}
.  endif

PKG_ARGS_INSTALL=	-p ${PREFIX} ${PKG_ARGS_COMMON}
PKG_ARGS_BINPKG=	-p ${PREFIX:S/^${DESTDIR}//} -L ${PREFIX} ${PKG_ARGS_COMMON}
.endif # !PKG_ARGS_COMMON

PKG_SUFX?=		.tgz
#PKG_SUFX?=		.tbz		# bzip2(1) pkgs
# where pkg_add records its dirty deeds.
PKG_DBDIR?=		${DESTDIR}/var/db/pkg

# Define SMART_MESSAGES in /etc/mk.conf for messages giving the tree
# of dependencies for building, and the current target.
.ifdef SMART_MESSAGES
_PKGSRC_IN?=		===> ${.TARGET} [${PKGNAME}${_PKGSRC_DEPS}] ===
.else
_PKGSRC_IN?=		===
.endif

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=		${ECHO}

# How to do nothing.  Override if you, for some strange reason, would rather
# do something.
DO_NADA?=		${TRUE}

ALL_TARGET?=		all
INSTALL_TARGET?=	install

.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET+=	install.man
.endif

# If this host is behind a filtering firewall, use passive ftp(1)
.if defined(PASSIVE_FETCH)
FETCH_BEFORE_ARGS += -p
.endif

# If USE_MOTIF (deprecated) is set, then include motif.buildlink.mk for the
# Motif discovery logic.
#
.if defined(USE_MOTIF)
.  include "../../mk/motif.buildlink.mk"
.endif

# If USE_XPM is set, depend on xpm.
.if defined(USE_XPM)
.  if (defined(HAVE_BUILTIN_XPM) && (${HAVE_BUILTIN_XPM} == "NO"))
DEPENDS+=		xpm-3.4k:../../graphics/xpm
XPMDIR_DEFAULT=		${X11PREFIX}
.  else
XPMDIR_DEFAULT=		${X11BASE}
.  endif
.  undef __BUILTIN_XPM
.endif	# USE_XPM

# If USE_MESA is set, depend on Mesa (or Mesa-glx if USE_GLX is defined and
# Mesa/GLX is not included in XFree86)
.if defined(USE_MESA)
.  if (defined(USE_GLX) && defined(HAVE_BUILTIN_MESA) && ${HAVE_BUILTIN_MESA} == "NO")
DEPENDS+=		Mesa-glx>=20000813:../../graphics/Mesa-glx
.  else
DEPENDS+=		Mesa>=3.2.1:../../graphics/Mesa
.  endif
.  undef __BUILTIN_MESA
.endif	# USE_MESA

# If USE_FREETYPE2 is set, depend on freetype2.
.if defined(USE_FREETYPE2)
.  if ${HAVE_BUILTIN_FREETYPE2} == "NO"
DEPENDS+=		freetype2>=2.0.1:../../graphics/freetype2
.  endif
.  undef __BUILTIN_FREETYPE2
.endif	# USE_FREETYPE2

# Check if we got "rman" with XFree86, for packages that need "rman". 
.if defined(USE_RMAN)
.  if !exists(${X11BASE}/bin/rman)
DEPENDS+=		rman-3.0.9:../../textproc/rman
RMAN?=			${LOCALBASE}/bin/rman
.  else
RMAN?=			${X11BASE}/bin/rman
.  endif
.endif

# Popular master sites
MASTER_SITE_XCONTRIB+=	\
	ftp://uiarchive.uiuc.edu/pub/ftp/ftp.x.org/contrib/ \
	ftp://sunsite.doc.ic.ac.uk/packages/X11/contrib/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/ \
	ftp://ftp.sunet.se/pub/X11/contrib/ \
	ftp://sunsite.sut.ac.jp/pub/archives/X11/contrib/ \
	ftp://sunsite.icm.edu.pl/pub/X11/contrib/ \
	ftp://ftp.task.gda.pl/mirror/ftp.x.org/contrib/ \
	ftp://ftp.ntua.gr/pub/X11/contrib/ \
	ftp://sunsite.cnlab-switch.ch/mirror/X11/contrib/ \
	ftp://ftp.cica.es/pub/X/contrib/ \
	ftp://ftp.unicamp.br/pub/X11/contrib/ \
	ftp://ftp.uni-paderborn.de/pub/X11/contrib/ \
	ftp://ftp.x.org/contrib/

MASTER_SITE_GNU+=	\
	ftp://ftp.gnu.org/pub/gnu/ \
	ftp://ftp.cs.columbia.edu/archives/gnu/prep/ \
	ftp://ftp.gwdg.de/pub/gnu/ \
	ftp://ftp.progsoc.uts.edu.au/pub/gnu/

MASTER_SITE_PERL_CPAN+=	\
	ftp://ftp.loaded.net/pub/CPAN/modules/by-module/ \
	ftp://ftp.freesoftware.com/pub/perl/CPAN/modules/by-module/ \
	ftp://ftp.gmd.de/mirrors/CPAN/modules/by-module/ \
	ftp://cpan.perl.org/CPAN/modules/by-module/

MASTER_SITE_R_CRAN+=	\
	http://cran.r-project.org/src/ \
	ftp://cran.r-project.org/pub/R/src/ \
	http://cran.at.r-project.org/src/ \
	ftp://cran.at.r-project.org/pub/R/src/ \
	http://cran.dk.r-project.org/src/ \
	http://cran.ch.r-project.org/src/ \
	http://cran.uk.r-project.org/src/ \
	http://cran.us.r-project.org/src/ \
	http://lib.stat.cmu.edu/R/CRAN/src/ \
	ftp://ftp.biostat.washington.edu/mirrors/R/CRAN/src/ \
	http://cran.stat.wisc.edu/src/ \
	http://SunSITE.auc.dk/R/src/ \
	http://www.stat.unipg.it/pub/stat/statlib/R/CRAN/src/ \
	ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/ \
	ftp://dola.snu.ac.kr/pub/R/CRAN/src/ \
	http://stat.ethz.ch/CRAN/src/ \
	http://www.stats.bris.ac.uk/R/src/

MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.cdrom.com/pub/tex/ctan/  \
	ftp://ftp.wustl.edu/packages/TeX/  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/  \
	ftp://ftp.tex.ac.uk/public/ctan/tex-archive/  \
	ftp://ftp.dante.de/tex-archive/

MASTER_SITE_SUNSITE+=	\
	ftp://sunsite.unc.edu/pub/Linux/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/ \
	ftp://ftp.informatik.rwth-aachen.de/pub/comp/Linux/sunsite.unc.edu/

MASTER_SITE_GNOME+=	\
	ftp://ftp.gnome.org/pub/GNOME/ \
	ftp://ftp.sunet.se/pub/X11/GNOME/ \
	ftp://ftp.tuwien.ac.at/hci/gnome.org/GNOME/

MASTER_SITE_SOURCEFORGE+=	\
	http://prdownloads.sourceforge.net/ \
	ftp://ftp3.sourceforge.net/pub/sourceforge/ \
	http://ftp2.sourceforge.net/ \
	http://ftp1.sourceforge.net/ \
	ftp://ftp.tuwien.ac.at/opsys/linux/sourceforge/

# Empty declaration to avoid "variable MASTER_SITES recursive" error
MASTER_SITES?=
PATCH_SITES?=

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/ \
	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/
.if defined(DIST_SUBDIR)
_MASTER_SITE_BACKUP:=	${MASTER_SITE_BACKUP:=${DIST_SUBDIR}/}
.  if defined(MASTER_SITE_OVERRIDE)
_MASTER_SITE_OVERRIDE:=	${MASTER_SITE_OVERRIDE:=${DIST_SUBDIR}/}
.  endif # MASTER_SITE_OVERRIDE
.else  # !DIST_SUBDIR
_MASTER_SITE_BACKUP:=	${MASTER_SITE_BACKUP}
.  if defined(MASTER_SITE_OVERRIDE)
_MASTER_SITE_OVERRIDE:= ${MASTER_SITE_OVERRIDE}
.  endif # MASTER_SITE_OVERRIDE
.endif # DIST_SUBDIR

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?= \
	${MASTER_SITE_BACKUP:=LOCAL_PORTS/}

# I guess we're in the master distribution business! :)  As we gain mirror
# sites for distfiles, add them to this list.
.if !defined(MASTER_SITE_OVERRIDE)
MASTER_SITES+=	${_MASTER_SITE_BACKUP}
PATCH_SITES+=	${_MASTER_SITE_BACKUP}
.else
MASTER_SITES:=	${_MASTER_SITE_OVERRIDE} ${MASTER_SITES}
PATCH_SITES:=	${_MASTER_SITE_OVERRIDE} ${PATCH_SITES}
.endif

# Derived names so that they're easily overridable.
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
.if defined(PKGREVISION) && ${PKGREVISION} != ""
.  if defined(PKGNAME)
PKGNAME:=		${PKGNAME}nb${PKGREVISION}
.  else
PKGNAME?=		${DISTNAME}nb${PKGREVISION}
.  endif
.else
PKGNAME?=		${DISTNAME}
.endif
SVR4_PKGNAME?=		${PKGNAME}

MAINTAINER?=		packages@netbsd.org

ALLFILES?=	${DISTFILES} ${PATCHFILES}
CKSUMFILES?=	${ALLFILES}
.for __tmp__ in ${IGNOREFILES}
CKSUMFILES:=	${CKSUMFILES:N${__tmp__}}
.endfor

# List of all files, with ${DIST_SUBDIR} in front.  Used for fetch and checksum.
.if defined(DIST_SUBDIR)
.  if ${CKSUMFILES} != ""
_CKSUMFILES?=	${CKSUMFILES:S/^/${DIST_SUBDIR}\//}
.  endif
_DISTFILES?=	${DISTFILES:S/^/${DIST_SUBDIR}\//}
_IGNOREFILES?=	${IGNOREFILES:S/^/${DIST_SUBDIR}\//}
_PATCHFILES?=	${PATCHFILES:S/^/${DIST_SUBDIR}\//}
.else
_CKSUMFILES?=	${CKSUMFILES}
_DISTFILES?=	${DISTFILES}
_IGNOREFILES?=	${IGNOREFILES}
_PATCHFILES?=	${PATCHFILES}
.endif

# This is what is actually going to be extracted, and is overridable
#  by user.
EXTRACT_ONLY?=	${DISTFILES}

.if !defined(CATEGORIES) || !defined(DISTNAME)
.BEGIN:
	@${ECHO_MSG} "CATEGORIES and DISTNAME are mandatory."
	@${FALSE}
.endif

.if defined(LIB_DEPENDS)
.BEGIN:
	@${ECHO_MSG} "LIB_DEPENDS is deprecated and must be replaced with DEPENDS."
	@${FALSE}
.endif

.if defined(PKG_PATH)
.BEGIN:
	@${ECHO_MSG} "Please unset PKG_PATH before doing pkgsrc works!"
	@${FALSE}
.endif

.if defined(MASTER_SITE_SUBDIR)
.BEGIN:
	@${ECHO_MSG} 'MASTER_SITE_SUBDIR is deprecated and must be replaced with MASTER_SITES.'
	@${FALSE}
.endif

.if defined(PATCH_SITE_SUBDIR)
.BEGIN:
	@${ECHO_MSG} 'PATCH_SITE_SUBDIR is deprecated and must be replaced with PATCH_SITES.'
	@${FALSE}
.endif

.if defined(ONLY_FOR_ARCHS) || defined(NOT_FOR_ARCHS) \
	|| defined(ONLY_FOR_OPSYS) || defined(NOT_FOR_OPSYS)
.BEGIN:
	@${ECHO_MSG} 'ONLY/NOT_FOR_ARCHS/OPSYS are deprecated and must be replaced with ONLY/NOT_FOR_PLATFORM.'
	@${FALSE}
.endif

PKGREPOSITORYSUBDIR?=	All
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
PKGFILE?=		${PKGREPOSITORY}/${PKGNAME}${PKG_SUFX}

CONFIGURE_SCRIPT?=	./configure
CONFIGURE_ENV+=		PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM} --prefix=${PREFIX}
HAS_CONFIGURE=		yes
.  if ${X11PREFIX} == ${LOCALBASE}
.    if !defined(X11_BUILDLINK_MK)
CONFIGURE_ARGS+=        --x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
.    endif
.  endif
.endif

# PKG_SYSCONFDIR is where the configuration files for a package may be found.
# This value may be customized in various ways:
#
# PKG_SYSCONFBASE is the main config directory under which all package
#	configuration files are to be found.
#
# PKG_SYSCONFSUBDIR is the subdirectory of PKG_SYSCONFBASE under which the
#	configuration files for a particular package may be found.
#
# PKG_SYSCONFDIR.${PKGBASE} overrides the value of ${PKG_SYSCONFDIR} for a
#	particular package.
#
# Users will typically want to set PKG_SYSCONFBASE to /etc, or accept the
# default location of ${PREFIX}/etc.
#
.if defined(PKG_SYSCONFDIR.${PKGBASE})
PKG_SYSCONFDIR=		${PKG_SYSCONFDIR.${PKGBASE}}
.else
PKG_SYSCONFSUBDIR?=	# empty
PKG_SYSCONFBASE?=	${PREFIX}/etc
.  if empty(PKG_SYSCONFSUBDIR)
PKG_SYSCONFDIR?=	${PKG_SYSCONFBASE}
.  else
PKG_SYSCONFDIR?=	${PKG_SYSCONFBASE}/${PKG_SYSCONFSUBDIR}
.  endif
.endif

CONFIGURE_ENV+=		PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"
MAKE_ENV+=		PKG_SYSCONFDIR="${PKG_SYSCONFDIR}"

# Passed to most of script invocations
SCRIPTS_ENV+= CURDIR=${.CURDIR} DISTDIR=${DISTDIR} \
	PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin \
	WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} \
	SCRIPTDIR=${SCRIPTDIR} FILESDIR=${FILESDIR} \
	PKGSRCDIR=${PKGSRCDIR} DEPENDS="${DEPENDS}" \
	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.if defined(BATCH)
SCRIPTS_ENV+=	BATCH=yes
.endif

.MAIN: all

# Use aliases, so that all versions of English are acceptable
.if defined(LICENCE) && !defined(LICENSE)
LICENSE=	${LICENCE}
.endif

.if defined(ACCEPTABLE_LICENCES) && !defined(ACCEPTABLE_LICENSES)
ACCEPTABLE_LICENSES=	${ACCEPTABLE_LICENCES}
.endif

################################################################
# Many ways to disable a package.
#
# If we're in BATCH mode and the package is interactive, or we're
# in interactive mode and the package is non-interactive, skip
# all the important targets. The reason we have two modes is that
# one might want to leave a build in BATCH mode running overnight,
# then come back in the morning and do _only_ the interactive ones
# that required your intervention.
#
# Ignore packages that can't be resold if building for a CDROM.
#
# Don't build a package if it's restricted and we don't want to
# get into that.
#
# Don't build any package that utilizes strong cryptography, for
# when the law of the land forbids it.
#
# Don't attempt to build packages against X if we don't have X.
#
# Don't build a package if it's broken.
################################################################

.if !defined(NO_IGNORE)
.  if (defined(IS_INTERACTIVE) && defined(BATCH))
IGNORE+= "${PKGNAME} is an interactive package"
.  endif
.  if (!defined(IS_INTERACTIVE) && defined(INTERACTIVE))
IGNORE+= "${PKGNAME} is not an interactive package"
.  endif
.  if (defined(NO_BIN_ON_CDROM) && defined(FOR_CDROM))
IGNORE+= "${PKGNAME} may not be placed in binary form on a CDROM:" \
         "    "${NO_BIN_ON_CDROM:Q}
.  endif
.  if (defined(NO_SRC_ON_CDROM) && defined(FOR_CDROM))
IGNORE+= "${PKGNAME} may not be placed in source form on a CDROM:" \
         "    "${NO_SRC_ON_CDROM:Q}
.  endif
.  if (defined(RESTRICTED) && defined(NO_RESTRICTED))
IGNORE+= "${PKGNAME} is restricted:" \
	 "    "${RESTRICTED:Q}
.  endif
.  if !(${MKCRYPTO} == "YES" || ${MKCRYPTO} == yes)
.    if (defined(CRYPTO) || defined(USE_SSL))
IGNORE+= "${PKGNAME} may not be built, because it utilizes strong cryptography"
.    endif
.  endif
.  if ((defined(USE_IMAKE) || defined(USE_X11BASE) || defined(USE_X11)) && \
       !exists(${X11BASE}))
IGNORE+= "${PKGNAME} uses X11, but ${X11BASE} not found"
.  endif
.  if defined(BROKEN)
IGNORE+= "${PKGNAME} is marked as broken:" ${BROKEN:Q}
.  endif

.  if defined(LICENSE)
.    ifdef ACCEPTABLE_LICENSES
.      for _lic in ${ACCEPTABLE_LICENSES}
.        if ${LICENSE} == "${_lic}"
_ACCEPTABLE=	yes
.        endif	# LICENSE == _lic
.      endfor	# _lic
.    endif	# ACCEPTABLE_LICENSES
.    ifndef _ACCEPTABLE
IGNORE+= "${PKGNAME} has an unacceptable license: ${LICENSE}." \
	 "    To build this package, add this line to your /etc/mk.conf:" \
	 "    ACCEPTABLE_LICENSES+=${LICENSE}"
.    endif	# _ACCEPTABLE
.  endif	# LICENSE

# Define __PLATFORM_OK only if the OS matches the pkg's allowed list.
.  if defined(ONLY_FOR_PLATFORM) && !empty(ONLY_FOR_PLATFORM)
.    for __tmp__ in ${ONLY_FOR_PLATFORM}
.      if ${MACHINE_PLATFORM:M${__tmp__}} != ""
__PLATFORM_OK?=	yes
.      endif	# MACHINE_PLATFORM
.    endfor	# __tmp__
.  else	# !ONLY_FOR_PLATFORM
__PLATFORM_OK?=	yes
.  endif	# ONLY_FOR_PLATFORM
.  for __tmp__ in ${NOT_FOR_PLATFORM}
.    if ${MACHINE_PLATFORM:M${__tmp__}} != ""
.      undef __PLATFORM_OK
.    endif	# MACHINE_PLATFORM
.  endfor	# __tmp__
.  if !defined(__PLATFORM_OK)
IGNORE+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}"
.  endif	# !__PLATFORM_OK

#
# Now print some error messages that we know we should ignore the pkg
#
.  if defined(IGNORE)
fetch checksum extract patch configure all build install package \
install-depends check-depends:
.    if defined(IGNORE_SILENT)
	@${DO_NADA}
.    else
	@for str in ${IGNORE} ; \
	do \
		${ECHO} "${_PKGSRC_IN}> $$str" ; \
	done
.    endif
.    if defined(IGNORE_FAIL)
	${FALSE}
.    endif
.  endif # IGNORE
.endif # !NO_IGNORE

# Add these defs to the ones dumped into +BUILD_DEFS
BUILD_DEFS+=	PKGPATH
BUILD_DEFS+=	OPSYS OS_VERSION MACHINE_ARCH MACHINE_GNU_ARCH
BUILD_DEFS+=	CPPFLAGS CFLAGS LDFLAGS
BUILD_DEFS+=	CONFIGURE_ENV CONFIGURE_ARGS
BUILD_DEFS+=	OBJECT_FMT LICENSE RESTRICTED
BUILD_DEFS+=	NO_SRC_ON_FTP NO_SRC_ON_CDROM
BUILD_DEFS+=	NO_BIN_ON_FTP NO_BIN_ON_CDROM

.if defined(OSVERSION_SPECIFIC)
BUILD_DEFS+=	OSVERSION_SPECIFIC
.endif # OSVERSION_SPECIFIC

.if !target(all)
all: build
.endif

.if !defined(DEPENDS_TARGET)
.  if make(package)
DEPENDS_TARGET=	package
.  elif make(update)
DEPENDS_TARGET=	update
.  else
DEPENDS_TARGET=	reinstall
.  endif
.endif

.if !defined(UPDATE_TARGET)
.  if ${DEPENDS_TARGET} == "update"
.    if make(package)
UPDATE_TARGET=	package
.    else
UPDATE_TARGET=	install
.    endif
.  else
UPDATE_TARGET=	${DEPENDS_TARGET}
.  endif
.endif

################################################################
# The following are used to create easy dummy targets for
# disabling some bit of default target behavior you don't want.
# They still check to see if the target exists, and if so don't
# do anything, since you might want to set this globally for a
# group of packages in a Makefile.inc, but still be able to
# override from an individual Makefile.
################################################################

# Disable checksum
.if (defined(NO_CHECKSUM) && !target(checksum)) || exists(${EXTRACT_COOKIE})
checksum: fetch
	@${DO_NADA}
.endif

# Disable patch
.if defined(NO_PATCH) && !target(patch)
patch: extract
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${PATCH_COOKIE}
.endif

# Disable configure
.if defined(NO_CONFIGURE) && !target(configure)
configure: patch
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}
.endif

# Disable build
.if defined(NO_BUILD) && !target(build)
build: configure
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}
.endif

# Disable install
.if defined(NO_INSTALL) && !target(install)
install: build
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.endif

# Disable package
.if defined(NO_PACKAGE) && !target(package)
package:
.  if defined(IGNORE_SILENT)
	@${DO_NADA}
.  else
	@${ECHO_MSG} "${_PKGSRC_IN}> ${PKGNAME} may not be packaged: ${NO_PACKAGE}."
.  endif
.endif

################################################################
# More standard targets start here.
#
# These are the body of the build/install framework.  If you are
# not happy with the default actions, and you can't solve it by
# adding pre-* or post-* targets/scripts, override these.
################################################################

# Fetch
_FETCH_FILE=								\
	if [ ! -f $$file -a ! -f $$bfile -a ! -h $$bfile ]; then	\
		${ECHO_MSG} "=> $$bfile doesn't seem to exist on this system."; \
		if [ ! -w ${_DISTDIR}/. ]; then 			\
			${ECHO_MSG} "=> Can't download to ${_DISTDIR} (permission denied?)."; \
			exit 1; 					\
		fi; 							\
		for site in $$sites; do					\
			${ECHO_MSG} "=> Attempting to fetch $$bfile from $${site}."; \
			if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${bfile} ${FETCH_AFTER_ARGS}; then \
				if [ -n "${FAILOVER_FETCH}" -a -f ${DISTINFO_FILE} -a -f ${_DISTDIR}/$$bfile ]; then \
					alg=`${AWK} 'NF == 4 && $$2 == "('$$file')" && $$3 == "=" {print $$1;}' ${DISTINFO_FILE}`; \
					if [ -z "$$alg" ]; then		\
						alg=${DIGEST_ALGORITHM};\
					fi;				\
					CKSUM=`${DIGEST} $$alg < ${_DISTDIR}/$$bfile`; \
					CKSUM2=`${AWK} '$$1 == "'$$alg'" && $$2 == "('$$file')" {print $$4;}' <${DISTINFO_FILE}`; \
					if [ "$$CKSUM" = "$$CKSUM2" -o "$$CKSUM2" = "IGNORE" ]; then \
						break;			\
					else				\
						${ECHO_MSG} "=> Checksum failure - trying next site."; \
					fi;				\
				elif [ ! -f ${_DISTDIR}/$$bfile ]; then \
					${ECHO_MSG} "=> FTP didn't fetch expected file, trying next site." ; \
				else					\
					break;				\
				fi;					\
			fi						\
		done;							\
		if [ ! -f ${_DISTDIR}/$$bfile ]; then \
			${ECHO_MSG} "=> Couldn't fetch $$bfile - please try to retrieve this";\
			${ECHO_MSG} "=> file manually into ${_DISTDIR} and try again."; \
			exit 1;						\
		fi;							\
	fi

_CHECK_DIST_PATH=							\
	if [ "X${DIST_PATH}" != "X" ]; then				\
		for d in "" ${DIST_PATH:S/:/ /g}; do	\
			if [ "X$$d" = "X" -o "X$$d" = "X${DISTDIR}" ]; then continue; fi; \
			if [ -f $$d/${DIST_SUBDIR}/$$bfile ]; then	\
				${ECHO} "Using $$d/${DIST_SUBDIR}/$$bfile"; \
				${RM} -f $$bfile;			\
				${LN} -s $$d/${DIST_SUBDIR}/$$bfile $$bfile; \
				break;					\
			fi;						\
		done;							\
	fi

#
# Sort the master site list according to the patterns in MASTER_SORT
#
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+= ${MASTER_SORT:S/./\\./g:C/.*/:\/\/[^\/]*&\//}

MASTER_SORT_AWK= BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX}"; }
.for srt in ${MASTER_SORT_REGEX}
MASTER_SORT_AWK+= /${srt:C/\//\\\//g}/ { good["${srt}"] = good["${srt}"] " " $$0 ; next; } 
.endfor
MASTER_SORT_AWK+= { rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }
SORTED_MASTER_SITES_CMD= ${ECHO} '${MASTER_SITES}' | ${AWK} '${MASTER_SORT_AWK}'
SORTED_PATCH_SITES_CMD= ${ECHO} '${PATCH_SITES}' | ${AWK} '${MASTER_SORT_AWK}'


.if !target(do-fetch)
do-fetch:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${_DISTDIR}
.for fetchfile in ${_DISTFILES}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR};			\
	sortedsites=`${SORTED_MASTER_SITES_CMD}`;			\
	sites="${MASTER_SITES_${fetchfile:T}} $$sortedsites";		\
	file="${fetchfile}";						\
	bfile="${fetchfile:T}";						\
	${_CHECK_DIST_PATH};						\
	${_FETCH_FILE}
.endfor
.  if defined(_PATCHFILES)
.for fetchfile in ${_PATCHFILES}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR};			\
	sortedsites=`${SORTED_PATCH_SITES_CMD}`;			\
	sites="${PATCH_SITES_${fetchfile:T}} $$sortedsites";		\
	file="${fetchfile}";						\
	bfile="${fetchfile:T}";						\
	${_CHECK_DIST_PATH};						\
	${_FETCH_FILE}
.endfor
.  endif
.endif

# show both build and run depends directories (non-recursively)
.if !target(show-depends-dirs)
show-depends-dirs:
	${_PKG_SILENT}${_PKG_DEBUG}                                     \
	dlist="";\
	thisdir=`pwd`;\
	for reldir in "" ${DEPENDS:C/^[^:]*://:C/:.*$//} ${BUILD_DEPENDS:C/^[^:]*://:C/:.*$//} ;\
	do \
		if [ "X$$reldir" = "X" ]; then continue; fi ;\
		cd $$thisdir/$$reldir ;\
		PWD=`pwd` ;\
		d=`dirname $$PWD` ;\
		absdir=`basename $$d`/`basename $$PWD` ;\
		dlist="$$dlist $$absdir";\
	done ;\
	cd $$thisdir ;\
	${ECHO} "$$dlist"
.endif

.if !target(show-distfiles)
show-distfiles:
.  if defined(IGNORE)
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.  else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for file in "" ${_CKSUMFILES}; do				\
		if [ "X$$file" = "X" ]; then continue; fi;		\
		${ECHO} $$file;						\
	done
.  endif
.endif

.if !target(show-downlevel)
show-downlevel:
.  if defined(IGNORE)
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.  else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_INFO} -e \"${PKGBASE}\" || ${TRUE}`";		\
	if [ "X$$found" != "X" -a "X$$found" != "X${PKGNAME}" ]; then	\
		${ECHO} "${PKGBASE} package: $$found installed, pkgsrc version ${PKGNAME}"; \
		if [ "X$$STOP_DOWNLEVEL_AFTER_FIRST" != "X" ]; then	\
			${ECHO} "stoping after first downlevel pkg found";	\
			exit 1;						\
		fi;							\
	fi
.  endif
.endif

.if !target(show-installed-depends)
show-installed-depends:
.  if defined(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for i in ${DEPENDS:C/:.*$//:Q:S/\ / /g} ; do			\
		echo "$$i =>" `${PKG_INFO} -e $$i` ;			\
	done
.  endif
.endif

.if defined(EVAL_PREFIX)
.  for def in ${EVAL_PREFIX}
.    if !defined(${def:C/=.*//}_DEFAULT)
${def:C/=.*//}_DEFAULT=	${X11PREFIX}
.    endif
.    if !defined(${def:C/=.*//})
_depend_${def:C/=.*//} != ${PKG_INFO} -e ${def:C/.*=//} 2>/dev/null; ${ECHO}
.      if (${_depend_${def:C/=.*//}} == "")
${def:C/=.*//}=${${def:C/=.*//}_DEFAULT}
.      else
_dir_${def:C/=.*//} != (${PKG_INFO} -qp ${def:C/.*=//} 2>/dev/null) | ${AWK} '{ print $$2; exit }'
${def:C/=.*//}=${_dir_${def:C/=.*//}}
MAKEFLAGS+= ${def:C/=.*//}=${_dir_${def:C/=.*//}}
.      endif
.    endif
.  endfor
.endif

.if !target(show-pkgsrc-dir)
show-pkgsrc-dir:
.  if defined(IGNORE)
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.  else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_INFO} -e \"${PKGWILDCARD}\" || ${TRUE}`";		\
	if [ "X$$found" != "X" ]; then					\
		${ECHO} ${PKGPATH};					\
	fi
.  endif
.endif


# Extract

DOWNLOADED_DISTFILE=	${_DISTDIR}/$$file

.if !target(do-extract)
do-extract:
.  ifndef KEEP_WRKDIR
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -rf ${WRKDIR}
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${WRKDIR}
.  ifdef WRKOBJDIR
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${WRKDIR_BASENAME} || ${TRUE};				\
	if ${LN} -s ${WRKDIR} ${WRKDIR_BASENAME} 2>/dev/null; then	\
		${ECHO} "${WRKDIR_BASENAME} -> ${WRKDIR}";		\
	fi
.  endif # WRKOBJDIR
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for file in "" ${EXTRACT_ONLY}; do				\
		if [ "X$$file" = X"" ]; then continue; fi;		\
		{ cd ${WRKDIR} && ${EXTRACT_CMD}; };			\
	done
.endif

# Patch

.if !target(do-patch)
do-patch: uptodate-digest
.  if defined(PATCHFILES)
	@${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patches for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR}; \
	  for i in ${PATCHFILES}; do \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patch $$i" ; \
		fi; \
		case $$i in \
			*.Z|*.gz) \
				${GZCAT} $$i | ${PATCH} ${PATCH_DIST_ARGS} \
				|| { ${ECHO} Patch $$i failed ; exit 1; } ; \
				;; \
			*.bz2) \
				${BZCAT} $$i | ${PATCH} ${PATCH_DIST_ARGS} \
				|| { ${ECHO} Patch $$i failed ; exit 1; } ; \
				;; \
			*) \
				${PATCH} ${PATCH_DIST_ARGS} < $$i \
				|| { ${ECHO} Patch $$i failed ; exit 1; } ; \
				;; \
		esac; \
	  done
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}if [ -d ${PATCHDIR} ]; then		\
		if [ "`${ECHO} ${PATCHDIR}/patch-*`" = "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "${_PKGSRC_IN}> Ignoring empty patch directory"; \
			if [ -d ${PATCHDIR}/CVS ]; then			\
				${ECHO_MSG} "${_PKGSRC_IN}> Perhaps you forgot the -P flag to cvs co or update?"; \
			fi;						\
		else							\
			${ECHO_MSG} "${_PKGSRC_IN}> Applying ${OPSYS} patches for ${PKGNAME}" ; \
			fail="";					\
			for i in ${PATCHDIR}/patch-* ${LOCALPATCHES}/${PKGPATH}/* ; do		\
				if [ "$$i" = "${LOCALPATCHES}/${PKGPATH}/*" ]; then \
					continue ; 			\
				fi ; 					\
				if [ ! -f "$$i" ]; then			\
					${ECHO_MSG} "${_PKGSRC_IN}> $$i is not a valid patch file - skipping" ; \
					continue ; 			\
				fi ; 					\
				case $$i in				\
				*.orig|*.rej|*~)			\
					${ECHO_MSG} "${_PKGSRC_IN}> Ignoring patchfile $$i" ; \
					continue;			\
					;;				\
				${PATCHDIR}/patch-local-*) 		\
					;;				\
				${LOCALPATCHES}/${PKGPATH}/*) 		\
					;;				\
				*)					\
					if [ -f ${DISTINFO_FILE} ]; then \
						filename=`expr $$i : '.*/\(.*\)'`; \
						algsum=`${AWK} 'NF == 4 && $$2 == "('$$filename')" && $$3 == "=" {print $$1 " " $$4}' ${DISTINFO_FILE} || ${TRUE}`; \
						if [ "X$$algsum" != "X" ]; then \
							alg=`${ECHO} $$algsum | ${AWK} '{ print $$1 }'`; \
							recorded=`${ECHO} $$algsum | ${AWK} '{ print $$2 }'`; \
							calcsum=`${SED} -e '/\$$NetBSD.*/d' $$i | ${DIGEST} $$alg`; \
							if [ ${PATCH_DEBUG_TMP} = yes ]; then	\
								${ECHO_MSG} "=> Verifying $$filename (using digest algorithm $$alg)" ; \
							fi;		\
						fi;			\
						if [ "X$$algsum" = "X" -o "X$$recorded" = "X" ]; then \
							${ECHO_MSG} "**************************************"; \
							${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
							${ECHO_MSG} "**************************************"; \
							continue;	\
						fi;			\
						if [ "X$$calcsum" != "X$$recorded" ]; then \
							${ECHO_MSG} "**************************************"; \
							${ECHO_MSG} "Patch file $$i has been modified"; \
							${ECHO_MSG} "**************************************"; \
							fail="$$fail $$filename"; \
							continue;	\
						fi;			\
					fi;				\
					;;				\
				esac;					\
				if [ ${PATCH_DEBUG_TMP} = yes ]; then	\
					${ECHO_MSG} "${_PKGSRC_IN}> Applying ${OPSYS} patch $$i" ; \
				fi;					\
				fuzz="";				\
				${PATCH} -v > /dev/null 2>&1 && fuzz="${PATCH_FUZZ_FACTOR}"; \
				${PATCH} $$fuzz ${PATCH_ARGS} < $$i ||	\
					{ ${ECHO} Patch $$i failed ; exit 1; } ; \
			done;						\
			if [ "X$$fail" != "X" ]; then			\
				${ECHO_MSG} "Patching failed due to modified patch file(s): $$fail"; \
				exit 1;					\
			fi;						\
		fi;							\
	fi
.endif

# Configure

# _CONFIGURE_PREREQ is a list of targets to run after pre-configure but before
#	do-configure.  These targets typically edit the files used by the
#	do-configure target.
#
# _CONFIGURE_POSTREQ is a list of targets to run after do-configure but before
#	post-configure.  These targets typically edit the files generated by
#	the do-configure target that are used during the build phase.

_CONFIGURE_PREREQ+=	replace-perl
replace-perl:
.if defined(REPLACE_PERL)
.  for f in ${REPLACE_PERL}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC};							\
	if [ -f ${f} ]; then						\
		${SED} "s,#!.*/bin/perl,#!${PERL5},"			\
			${f} > ${f}.new;				\
		if [ -x ${f} ]; then					\
			${CHMOD} a+x ${f}.new;				\
		fi;							\
		${MV} -f ${f}.new ${f};					\
	fi
.  endfor
.else
	${_PKG_SILENT}${_PKG_DEBUG}${TRUE}
.endif

_CONFIGURE_PREREQ+=	do-ltconfig-override
do-ltconfig-override:
.if defined(USE_LIBTOOL) && defined(LTCONFIG_OVERRIDE)
.  for ltconfig in ${LTCONFIG_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${ltconfig} ]; then					\
		${RM} -f ${ltconfig};					\
		${ECHO} "${RM} -f libtool; ${LN} -s ${LIBTOOL} libtool"	\
			> ${ltconfig};					\
		${CHMOD} +x ${ltconfig};				\
	fi
.  endfor
.else
	${_PKG_SILENT}${_PKG_DEBUG}${TRUE}
.endif

# By default, prevent invocation of GNU "auto*" driven by the generated
# Makefiles during the build process by touching various auto{conf,make}
# source files to make them up-to-date.  Packages that require regenerating
# the configure script and Makefile.in files should make the appropriate
# calls to auto{conf,make} in a pre-configure target.
#
AUTOMAKE_OVERRIDE?=	YES
.if defined(AUTOMAKE_OVERRIDE) && (${AUTOMAKE_OVERRIDE} == "YES")
AUTOMAKE_PATTERNS+=	*.m4
AUTOMAKE_PATTERNS+=	*.in
AUTOMAKE_PATTERNS+=	${CONFIGURE_SCRIPT:T}*
_AUTOMAKE_PATTERNS_FIND=	\
	\( ${AUTOMAKE_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)

_CONFIGURE_PREREQ+=	suppress-automake
suppress-automake:
.  if defined(HAS_CONFIGURE)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC};							\
	${FIND} . ${_AUTOMAKE_PATTERNS_FIND} -print |			\
		${XARGS} ${TOUCH} ${TOUCH_ARGS}
.  else
	${_PKG_SILENT}${_PKG_DEBUG}${TRUE}
.  endif
.endif	# AUTOMAKE_OVERRIDE

.if !target(do-configure)
do-configure: ${_CONFIGURE_PREREQ}
.  if defined(HAS_CONFIGURE)
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} \
	    CC="${CC}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
	    CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
	    INSTALL="`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'` -c -o ${BINOWN} -g ${BINGRP}" \
	    ac_given_INSTALL="`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'` -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.  endif
.  if defined(USE_IMAKE)
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} ${XMKMF}
.  endif
.endif

_CONFIGURE_POSTREQ+=	do-libtool-override
do-libtool-override:
.if defined(USE_LIBTOOL) && defined(LIBTOOL_OVERRIDE)
.  for libtool in ${LIBTOOL_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${libtool} ]; then					\
		${RM} -f ${libtool};					\
		${LN} -sf ${LIBTOOL} ${libtool};			\
	fi
.  endfor
.else
	${_PKG_SILENT}${_PKG_DEBUG}${TRUE}
.endif

post-configure: ${_CONFIGURE_POSTREQ}

# Build

.if !target(do-build)
do-build:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}
.endif

# Install

.if !target(do-install)
do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}
.endif

# Package

.if !target(real-su-package)
real-su-package: ${PLIST} ${DESCR}
	${_PKG_SILENT}${_PKG_DEBUG}\
	${ECHO_MSG} "${_PKGSRC_IN}> Building binary package for ${PKGNAME}"; \
	if [ ! -d ${PKGREPOSITORY} ]; then			\
		${MKDIR} ${PKGREPOSITORY};			\
		if [ $$? -ne 0 ]; then				\
			${ECHO_MSG} "=> Can't create directory ${PKGREPOSITORY}."; \
			exit 1;					\
		fi;						\
	fi;							\
	if ${PKG_CREATE} ${PKG_ARGS_BINPKG} ${PKGFILE}; then	\
		${MAKE} ${MAKEFLAGS} package-links;		\
	else							\
		${MAKE} ${MAKEFLAGS} delete-package;		\
		exit 1;						\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${PACKAGE_COOKIE}
.  if defined(NO_BIN_ON_CDROM)
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ${PKGNAME} may not be put on a CD-ROM:"
	@${ECHO_MSG} "${_PKGSRC_IN}>         " ${NO_BIN_ON_CDROM:Q}
.  endif
.  if defined(NO_BIN_ON_FTP)
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ${PKGNAME} may not be made available through FTP:"
	@${ECHO_MSG} "${_PKGSRC_IN}>         " ${NO_BIN_ON_FTP:Q}
.  endif
.endif

# Some support rules for real-su-package

.if !target(package-links)
package-links:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} delete-package-links
	${_PKG_SILENT}${_PKG_DEBUG}for cat in ${CATEGORIES}; do		\
		if [ ! -d ${PACKAGES}/$$cat ]; then			\
			${MKDIR} ${PACKAGES}/$$cat;			\
			if [ $$? -ne 0 ]; then				\
				${ECHO_MSG} "=> Can't create directory ${PACKAGES}/$$cat."; \
				exit 1;					\
			fi;						\
		fi;							\
		${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX};	\
		${LN} -s ../${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PACKAGES}/$$cat; \
	done;
.endif

.if !target(delete-package-links)
delete-package-links:
	${_PKG_SILENT}${_PKG_DEBUG}\
	${FIND} ${PACKAGES} -type l -name ${PKGNAME}${PKG_SUFX} | ${XARGS} ${RM} -f
.endif

.if !target(delete-package)
delete-package:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} delete-package-links
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${PKGFILE}
.endif

real-su-install: ${MESSAGE}
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
.  if defined(CONFLICTS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${WRKDIR}/.CONFLICTS
.    for conflict in ${CONFLICTS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_INFO} -e \"${conflict}\" || ${TRUE}`";		\
	if [ X"$$found" != X"" ]; then					\
		${ECHO} "$$found" >> ${WRKDIR}/.CONFLICTS;		\
	fi
.    endfor
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -s ${WRKDIR}/.CONFLICTS ]; then \
		found=`${SED} -e s'|${PKG_DBDIR}/||g' ${WRKDIR}/.CONFLICTS | tr '\012' ' '`; \
		${ECHO_MSG} "${_PKGSRC_IN}> ${PKGNAME} conflicts with installed package(s): $$found found."; \
		${ECHO_MSG} "*** They install the same files into the same place."; \
		${ECHO_MSG} "*** Please remove $$found first with pkg_delete(1)."; \
		${RM} -f ${WRKDIR}/.CONFLICTS;				\
		exit 1;							\
	fi
.  endif	# CONFLICTS
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_INFO} -e \"${PKGWILDCARD}\" || ${TRUE}`";		\
	if [ "$$found" != "" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}>  $$found is already installed - perhaps an older version?"; \
		${ECHO_MSG} "*** If so, you may wish to \`\`pkg_delete $$found'' and install"; \
		${ECHO_MSG} "*** this package again by \`\`${MAKE} reinstall'' to upgrade it properly,"; \
		${ECHO_MSG} "*** or use \`\`${MAKE} update'' to upgrade it and all of its dependencies."; \
		${ECHO_MSG} "*** If you really wish to overwrite the old package of $$found"; \
		${ECHO_MSG} "*** without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
		${ECHO_MSG} "*** in your environment or the \"${MAKE} install\" command line."; \
		exit 1;							\
	fi
.endif # !NO_PKG_REGISTER && !NO_FORCE_REGISTER
	${_PKG_SILENT}${_PKG_DEBUG}if [ `${SH} -c umask` -ne ${DEF_UMASK} ]; then \
		${ECHO_MSG} "${_PKGSRC_IN}>  Warning: your umask is \"`${SH} -c umask`"\".; \
		${ECHO_MSG} "If this is not desired, set it to an appropriate value (${DEF_UMASK})"; \
		${ECHO_MSG} "and install this package again by \`\`${MAKE} deinstall reinstall''."; \
	fi
.if !defined(NO_MTREE)
	${_PKG_SILENT}${_PKG_DEBUG}if [ `${ID} -u` = 0 ]; then		\
		if [ ! -f ${MTREE_FILE} ]; then				\
			${ECHO_MSG} "Error: mtree file \"${MTREE_FILE}\" is missing."; \
			exit 1;						\
		else							\
			if [ ! -d ${PREFIX} ]; then			\
				${MKDIR} ${PREFIX};			\
			fi;						\
			${MTREE} ${MTREE_ARGS} ${PREFIX}/;		\
		fi;							\
	else								\
		${ECHO_MSG} "Warning: not superuser, can't run mtree."; \
		${ECHO_MSG} "Become root and try again to ensure correct permissions."; \
	fi
.endif # !NO_MTREE
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} pre-install-script
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} pre-install
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} do-install
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} post-install
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKEFLAGS} post-install-script
.for f in ${INFO_FILES}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} "install-info --info-dir=${PREFIX}/info ${PREFIX}/info/${f}"; \
	install-info --remove --info-dir=${PREFIX}/info ${PREFIX}/info/${f}; \
	install-info --info-dir=${PREFIX}/info ${PREFIX}/info/${f}
.endfor
	@# PLIST must be generated at this late point (instead of
	@# depending on it somewhere earlier), as the
	@# pre/do/post-install aren't run then yet:
	@${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} ${PLIST}
	${_PKG_SILENT}${_PKG_DEBUG}newmanpages=`${EGREP} -h		\
		'^([^@/]*/)*man/([^/]*/)?(man[1-9ln]/.*\.[1-9ln]|cat[1-9ln]/.*\.0)(\.gz)?$$' \
		${PLIST} 2>/dev/null || ${TRUE}`;			\
	if [ X"${MANCOMPRESSED}" != X"" -a X"${MANZ}" = X"" ]; then	\
		${ECHO_MSG} "${_PKGSRC_IN}> [Automatic manual page handling]";	\
		${ECHO_MSG} "${_PKGSRC_IN}> Decompressing manual pages for ${PKGNAME}";	\
		for manpage in $$newmanpages; do			\
			manpage=`${ECHO} $$manpage | ${SED} -e 's|\.gz$$||'`; \
			if [ -h ${PREFIX}/$$manpage.gz ]; then		\
				set - `${FILE_CMD} ${PREFIX}/$$manpage.gz | ${SED} -e 's|\.gz$$||'`; \
				shift `expr $$# - 1`;			\
				${RM} -f ${PREFIX}/$$manpage;		\
				${LN} -s $${1} ${PREFIX}/$$manpage;	\
				${RM} ${PREFIX}/$$manpage.gz;		\
			else						\
				${GUNZIP_CMD} ${PREFIX}/$$manpage.gz;	\
			fi;						\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$manpage";		\
			fi;						\
		done;							\
	fi;								\
	if [ X"${MANCOMPRESSED}" = X"" -a X"${MANZ}" != X"" ]; then	\
		${ECHO_MSG} "${_PKGSRC_IN}> [Automatic manual page handling]";	\
		${ECHO_MSG} "${_PKGSRC_IN}> Compressing manual pages for ${PKGNAME}"; \
		for manpage in $$newmanpages; do			\
			manpage=`${ECHO} $$manpage | ${SED} -e 's|\.gz$$||'`; \
			if [ -h ${PREFIX}/$$manpage ]; then		\
				set - `${FILE_CMD} ${PREFIX}/$$manpage`;	\
				shift `expr $$# - 1`;			\
				${RM} -f ${PREFIX}/$$manpage.gz; 	\
				${LN} -s $${1}.gz ${PREFIX}/$$manpage.gz; \
				${RM} ${PREFIX}/$$manpage;		\
			else						\
				${GZIP_CMD} ${PREFIX}/$$manpage;	\
			fi;						\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$manpage";		\
			fi;						\
		done;							\
	fi
.if ${_DO_SHLIB_CHECKS} == "yes"
	${_PKG_SILENT}${_PKG_DEBUG}\
	${MAKE} ${MAKEFLAGS} do-shlib-handling SHLIB_PLIST_MODE=0
.endif
.ifdef MESSAGE
	@${ECHO_MSG} "${_PKGSRC_IN}> Please note the following:"
	@${ECHO_MSG} ""
	@${CAT} ${MESSAGE}
	@${ECHO_MSG} ""
.endif
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} fake-pkg
.endif # !NO_PKG_REGISTER
	${_PKG_SILENT}${_PKG_DEBUG}${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.if defined(PKG_DEVELOPER) && (${CHECK_SHLIBS} == "YES")
	@${MAKE} ${MAKEFLAGS} check-shlibs
.endif



# Do handling of shared libs for two cases:
#
# SHLIB_PLIST_MODE=1: when first called via the ${PLIST} target,
#                     update the PLIST to contain ELF symlink, run
#                     ldconfig on a.out,  etc. (used when called via
#                     the ${PLIST} target). Will update ${PLIST}.
# SHLIB_PLIST_MODE=0: when called via the real-su-install target,
#                     actually generate symlinks for ELF, run ldconfig
#                     for a.out, etc. Will not modify ${PLIST}.
#
# XXX This target could need some cleanup after it was ripped out of
#     real-su-install
#
do-shlib-handling:
.if ${SHLIB_HANDLING} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	sos=`${EGREP} -h -x '.*/lib[^/]+\.so\.[0-9]+(\.[0-9]+)+' ${PLIST} || ${TRUE}`; \
	if [ "$$sos" != "" ]; then					\
		shlib_type=`${MAKE} ${MAKEFLAGS} show-shlib-type`;	\
		if [ "${SHLIB_PLIST_MODE}" = "0" ]; then 		\
			${ECHO_MSG} "${_PKGSRC_IN}> [Automatic $$shlib_type shared object handling]"; \
		fi;  							\
		case "$$shlib_type" in					\
		ELF) 	;;						\
		"a.out") 						\
			${AWK} ' 					\
				BEGIN { linkc = 1 }			\
				/^@/ { lines[NR] = $$0; next }		\
				function libtool_release(lib) {		\
					if (gsub("-[^-]+\.so\.", "\.so\.", lib)) { \
						if (system("${TEST} -h ${PREFIX}/" lib) == 0) { \
							rels[NR] = lib; \
						}			\
					}				\
				}					\
				/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+\.[0-9]+$$/ { \
					libtool_release($$0);		\
					lines[NR] = $$0;		\
					sub("\.[0-9]+$$", "");		\
					links[linkc++] = $$0;		\
					sub("\.[0-9]+$$", "");		\
					links[linkc++] = $$0;		\
					sub("\.[0-9]+$$", "");		\
					links[linkc++] = $$0;		\
					if (sub("-[^-]+\.so$$", "\.so")) { \
						links[linkc++] = $$0;	\
					}				\
					next				\
				}					\
				/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+$$/ {	\
					libtool_release($$0);		\
					lines[NR] = $$0;		\
					sub("\.[0-9]+$$", "");		\
					links[linkc++] = $$0;		\
					sub("\.[0-9]+$$", "");		\
					links[linkc++] = $$0;		\
					if (sub("-[^-]+\.so$$", "\.so")) { \
						links[linkc++] = $$0;	\
					}				\
					next				\
				}					\
				{ lines[NR] = $$0 }			\
				END {					\
					for (i = 1 ; i <= linkc ; i++)	\
						for (j = 1 ; j < NR ; j++) \
							if (lines[j] == links[i]) \
								lines[j] = "@comment " lines[j]; \
					if (${SHLIB_PLIST_MODE}) 	\
						for (i = 1 ; i <= NR ; i++) { \
							print lines[i]; \
							if (rels[i] != "") \
								print rels[i]; \
						}			\
				}					\
			' <${PLIST} >${PLIST}.tmp ;			\
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then	\
				${MV} ${PLIST}.tmp ${PLIST};		\
			else 						\
				${RM} ${PLIST}.tmp ;			\
			fi ; 						\
			cnt=`${EGREP} -c -x '@exec[ 	]*${LDCONFIG}' ${PLIST} || ${TRUE}`; \
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then 	\
				if [ $$cnt -eq 0 ]; then		\
					${ECHO} "@exec ${LDCONFIG}" >> ${PLIST}; \
					${ECHO} "@unexec ${LDCONFIG}" >> ${PLIST}; \
				fi					\
			fi;						\
			if [ "${SHLIB_PLIST_MODE}" = "0" ]; then	\
				if [ "${PKG_VERBOSE}" != "" ]; then	\
					${ECHO_MSG} "$$sos";		\
					${ECHO_MSG} "Running ${LDCONFIG}"; \
				fi;					\
				${LDCONFIG} || ${TRUE};			\
			fi						\
			;;						\
		"*")							\
			if [ "${SHLIB_PLIST_MODE}" = "0" ]; then 	\
				${ECHO_MSG} "No shared libraries for ${MACHINE_ARCH}"; \
			fi ; 						\
			if [ "${SHLIB_PLIST_MODE}" = "1" ]; then	\
				for so in $$sos; do			\
					if [ X"${PKG_VERBOSE}" != X"" ]; then \
						${ECHO_MSG} >&2 "Ignoring $$so"; \
					fi;				\
					${SED} -e "s;^$$so$$;@comment No shared objects - &;" \
						${PLIST} >${PLIST}.tmp && ${MV} ${PLIST}.tmp ${PLIST};	\
				done;					\
			fi ;						\
			;;						\
		esac;							\
	fi
.endif # SHLIB_HANDLING == "YES"


# Check if all binaries and shlibs find their needed libs
# Must be run after "make install", so that files are installed, and
# ${PLIST} exists.
#
check-shlibs:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}\
	bins=`${PKG_INFO} -qL ${PKGNAME} | { ${EGREP} -h '/(bin|sbin|libexec)/' || ${TRUE}; }`; \
	if [ "${OBJECT_FMT}" = "ELF" ]; then \
		shlibs=`${PKG_INFO} -qL ${PKGNAME} | { ${EGREP} -h '/lib/lib.*.so' || ${TRUE}; }`; \
	else \
		shlibs=""; \
	fi ; \
	if [ X${LDD} = X ]; then \
		ldd=`${TYPE} ldd | ${AWK} '{ print $$NF }'` ; \
	else \
		ldd="${LDD}" ; \
	fi ; \
	for i in $${bins} $${shlibs} ; do \
		err=`{ $$ldd $$i 2>&1 || ${TRUE}; } | { ${GREP} "not found" || ${TRUE}; }`; \
		if [ "${PKG_VERBOSE}" != "" ]; then \
			${ECHO} "$$ldd $$i" ; \
		fi ; \
		if [ "$$err" != "" ]; then \
			${ECHO} "$$i: $$err" ; \
			error=1; \
		fi ; \
	done ; \
	if [ "$$error" = 1 ]; then \
		${ECHO} "*** The above programs/libs will not find the listed shared libraries"; \
		${ECHO} "    at runtime. Please fix the package (add -Wl,-R.../lib in the right places)!" ; \
		${SHCOMMENT} Might not error-out for non-pkg-developers; \
		exit 1 ; \
	fi
.endif # NO_PKG_REGISTER


.if !target(show-shlib-type)
# Show the shared lib type being built: one of ELF, a.out or none
show-shlib-type:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKDIR} &&							\
	sotype=none;							\
	if [ "X${MKPIC}" != "Xno" -a "X${NOPIC}" = "X" ]; then		\
		${ECHO} "int main() { exit(0); }" > a.$$$$.c;		\
		${CC} ${CFLAGS} a.$$$$.c -o a.$$$$.out;			\
		case `${FILE_CMD} a.$$$$.out` in			\
		*ELF*dynamically*)					\
			sotype=ELF ;;					\
		*shared*library*)					\
			sotype="a.out" ;;				\
		*dynamically*)						\
			sotype="a.out" ;;				\
		esac;							\
	fi;								\
	${ECHO} "$$sotype";						\
	${RM} -f a.$$$$.c a.$$$$.out
.endif


################################################################
# Skeleton targets start here
# 
# You shouldn't have to change these.  Either add the pre-* or
# post-* targets/scripts or redefine the do-* targets.  These
# targets don't do anything other than checking for cookies and
# call the necessary targets/scripts.
################################################################

.if !target(fetch)
fetch:
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-fetch
.endif

.if !target(extract)
extract: checksum ${EXTRACT_COOKIE}
.endif

.if !target(patch)
patch: extract ${PATCH_COOKIE}
.endif

.if !target(configure)
configure: patch ${CONFIGURE_COOKIE}
.endif

.if !target(build)
build: configure ${BUILD_COOKIE}
.endif

.if !target(install)
install: uptodate-pkgtools build ${INSTALL_COOKIE}
.endif

.if !target(package)
package: uptodate-pkgtools install ${PACKAGE_COOKIE}
.endif

${EXTRACT_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-extract DEPENDS_TARGET=${DEPENDS_TARGET}
${PATCH_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-patch
${CONFIGURE_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-configure
${BUILD_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-build
${INSTALL_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-install
${PACKAGE_COOKIE}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} real-package

extract-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Extracting for ${PKGNAME}"
patch-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Patching for ${PKGNAME}"
configure-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Configuring for ${PKGNAME}"
build-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Building for ${PKGNAME}"

extract-cookie:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} ${PKGNAME} >> ${EXTRACT_COOKIE}
patch-cookie:
	${_PKG_SILENT}${_PKG_DEBUG} ${TOUCH} ${TOUCH_FLAGS} ${PATCH_COOKIE}
configure-cookie:
	${_PKG_SILENT}${_PKG_DEBUG} ${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}
build-cookie:
	${_PKG_SILENT}${_PKG_DEBUG} ${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}

.ORDER: pre-fetch do-fetch post-fetch
.ORDER: extract-message install-depends pre-extract do-extract post-extract extract-cookie
.ORDER: patch-message pre-patch do-patch post-patch patch-cookie
.ORDER: configure-message pre-configure do-configure post-configure configure-cookie
.ORDER: build-message pre-build do-build post-build build-cookie

# Please note that the order of the following targets is important, and
# should not be modified (.ORDER is not recognised by make(1) in a serial
# make i.e. without -j n)
real-fetch: pre-fetch do-fetch post-fetch
real-extract: extract-message install-depends pre-extract do-extract post-extract extract-cookie
real-patch: patch-message pre-patch do-patch post-patch patch-cookie
real-configure: configure-message pre-configure do-configure post-configure configure-cookie
real-build: build-message pre-build do-build post-build build-cookie
real-install: do-su-install
real-package: do-su-package

_SU_TARGET=								\
	if [ `${ID} -u` = 0 ]; then					\
		${MAKE} ${MAKEFLAGS} $$realtarget;			\
	elif [ "X${BATCH}" != X"" ]; then				\
		${ECHO_MSG} "Warning: Batch mode, not superuser, can't run mtree."; \
		${ECHO_MSG} "Become root and try again to ensure correct permissions."; \
	else								\
		args="";						\
		if [ "X${FORCE_PKG_REGISTER}" != X"" ]; then		\
			args="FORCE_PKG_REGISTER=1";			\
		fi;							\
		if [ "X${PKG_DEBUG_LEVEL}" != X"" ]; then		\
			args="$$args PKG_DEBUG_LEVEL=${PKG_DEBUG_LEVEL}"; \
		fi;							\
		if [ "X${PRE_ROOT_CMD}" != "X${TRUE}" ]; then		\
			${ECHO} "*** WARNING *** Running: ${PRE_ROOT_CMD}"; \
			${PRE_ROOT_CMD};				\
		fi;                                             	\
		${ECHO_MSG} "${_PKGSRC_IN}> Becoming root@`/bin/hostname` to $$action ${PKGNAME}."; \
		${ECHO_MSG} -n "`${ECHO} ${SU_CMD} | ${AWK} '{ print $$1 }'` ";\
		${SU_CMD} "cd ${.CURDIR}; ${MAKE} $$args ${MAKEFLAGS} $$realtarget $$realflags"; \
	fi

do-su-install: 
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extractname=`${CAT} ${EXTRACT_COOKIE}`;				\
	case "$$extractname" in						\
	"")	${ECHO_MSG} "*** Warning: ${WRKDIR} may contain an older version of ${PKGBASE}" ;; \
	"${PKGNAME}")	;;						\
	*)	${ECHO_MSG} "*** Error: Package version $$extractname in ${WRKDIR}"; \
		${ECHO_MSG} "*** Current version ${PKGNAME} in pkgsrc directory"; \
		${ECHO_MSG} "*** Please rebuild the package using the newer version: \"${MAKE} clean && ${MAKE}\""; \
		exit 1 ;;						\
	esac
	@${ECHO_MSG} "${_PKGSRC_IN}> Installing for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-install";					\
	action="install";						\
	${_SU_TARGET} 

do-su-package:
	@${ECHO_MSG} "${_PKGSRC_IN}> Packaging ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-package";					\
	action="package";						\
	${_SU_TARGET} 

# Empty pre-* and post-* targets

.for name in fetch extract patch configure build install-script install package

.  if !target(pre-${name})
pre-${name}:
	@${DO_NADA}
.  endif

.  if !target(post-${name})
post-${name}:
	@${DO_NADA}
.  endif

.endfor

# Reinstall
#
# Special target to re-run install

.if !target(reinstall)
reinstall:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE} ${PLIST}
	${_PKG_SILENT}${_PKG_DEBUG}DEPENDS_TARGET=${DEPENDS_TARGET} ${MAKE} ${MAKEFLAGS} install
.endif

# Deinstall
#
# Special target to remove installation

.if !target(deinstall)
deinstall: do-su-deinstall

do-su-deinstall: uptodate-pkgtools
	@${ECHO_MSG} "${_PKGSRC_IN}> Deinstalling for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-deinstall";					\
	realflags="DEINSTALLDEPENDS=${DEINSTALLDEPENDS}";		\
	action="deinstall";						\
	${_SU_TARGET} 

.  if (${DEINSTALLDEPENDS} != "NO")
.    if (${DEINSTALLDEPENDS} != "ALL")
# used for removing stuff in bulk builds
real-su-deinstall-flags+=	-r -R
# used for "update" target
.    else
real-su-deinstall-flags+=	-r
.    endif
.  endif
.  ifdef PKG_VERBOSE
real-su-deinstall-flags+=	-v
.  endif

real-su-deinstall:
	${_PKG_SILENT}${_PKG_DEBUG} \
	found="`${PKG_INFO} -e \"${PKGWILDCARD}\" || ${TRUE}`"; \
	if [ "$$found" != "" ]; then \
		${ECHO} Running ${PKG_DELETE} ${real-su-deinstall-flags} $$found ; \
		${PKG_DELETE} ${real-su-deinstall-flags} $$found || ${TRUE} ; \
	fi
.  if (${DEINSTALLDEPENDS} != "NO") && (${DEINSTALLDEPENDS} != "ALL")
	@${SHCOMMENT} Also remove BUILD_DEPENDS:
.    for pkg in ${BUILD_DEPENDS:C/:.*$//}
	${_PKG_SILENT}${_PKG_DEBUG} \
	found="`${PKG_INFO} -e \"${pkg}\" || ${TRUE}`"; \
	if [ "$$found" != "" ]; then \
		${ECHO} Running ${PKG_DELETE} $$found ; \
		${PKG_DELETE} ${real-su-deinstall-flags} $$found || ${TRUE} ; \
	fi
.    endfor
.  endif # DEINSTALLDEPENDS
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif						# target(deinstall)


################################################################
# Some more targets supplied for users' convenience
################################################################

# The 'update' target can be used to update a package and all
# currently installed packages that depend upon this package.

.if exists(${DDIR})
RESUMEUPDATE?=	YES
CLEAR_DIRLIST?=	NO

update:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG}				\
		"${_PKGSRC_IN}> Resuming update for ${PKGNAME}"
.  if ${REINSTALL} != "NO"
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} deinstall DEINSTALLDEPENDS=ALL
.  endif
.else
RESUMEUPDATE?=	NO
CLEAR_DIRLIST?=	YES

update:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} ${DDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} deinstall DEINSTALLDEPENDS=ALL
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} ${UPDATE_TARGET} KEEP_WRKDIR=YES	\
			DEPENDS_TARGET=${DEPENDS_TARGET}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	[ ! -s ${DDIR} ] || for dep in `${CAT} ${DDIR}` ; do		\
		(if cd ../.. && cd "$${dep}" ; then				\
			${ECHO_MSG} "${_PKGSRC_IN}> Installing in $${dep}" &&	\
			if [ "${RESUMEUPDATE}" = "NO" -o 		\
			     "${REINSTALL}" != "NO" ] ; then		\
				${MAKE} ${MAKEFLAGS} deinstall;		\
			fi &&						\
			${MAKE} ${MAKEFLAGS} ${UPDATE_TARGET}		\
				DEPENDS_TARGET=${DEPENDS_TARGET} ;	\
		else							\
			${ECHO_MSG} "${_PKGSRC_IN}> Skipping removed directory $${dep}";\
		fi) ;							\
	done
.if ${NOCLEAN} == "NO"
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} clean-update CLEAR_DIRLIST=YES
.endif


clean-update:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} ${DDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -s ${DDIR} ] ; then					\
		for dep in `${CAT} ${DDIR}` ; do			\
			(if cd ../.. && cd "$${dep}" ; then			\
				${MAKE} ${MAKEFLAGS} clean ;		\
			else						\
				${ECHO_MSG} "${_PKGSRC_IN}> Skipping removed directory $${dep}";\
			fi) ;						\
		done ;							\
	fi
.if ${CLEAR_DIRLIST} != "NO"
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} clean
.else
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} clean update-dirlist		\
		DIRLIST="`${CAT} ${DDIR}`" PKGLIST="`${CAT} ${DLIST}`"
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG}				\
		"${_PKGSRC_IN}> Warning: preserved leftover directory list.  Your next";\
		${ECHO_MSG} "${_PKGSRC_IN}>          \`\`${MAKE} update'' may fail.  It is advised to use";\
		${ECHO_MSG} "${_PKGSRC_IN}>          \`\`${MAKE} update REINSTALL=YES'' instead!"
.endif


update-dirlist:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} -p ${WRKDIR}
.ifdef PKGLIST
.  for __tmp__ in ${PKGLIST}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >>${DLIST} "${__tmp__}"
.  endfor
.endif
.ifdef DIRLIST
.  for __tmp__ in ${DIRLIST}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >>${DDIR} "${__tmp__}"
.  endfor
.endif


${DDIR}: ${DLIST}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	ddir=`${SED} 's:-[^-]*$$::' ${DLIST}`;				\
	${ECHO} >${DDIR};						\
	for pkg in $${ddir} ; do					\
		if ${PKG_INFO} -b $${pkg} >/dev/null 2>&1 ; then	\
			${PKG_INFO} -b $${pkg} | ${SED}	-ne		\
			    's,\([^/]*/[^/]*\)/Makefile:.*,\1,p' | 	\
			    ${HEAD} -1 >>${DDIR};			\
		fi ;							\
	done

${DLIST}:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} -p ${WRKDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	{ ${PKG_INFO} -R "${PKGWILDCARD}" || ${TRUE}; } |		\
		${TAIL} -n +4 >${DLIST}

# The 'info' target can be used to display information about a package.
info: uptodate-pkgtools
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_INFO} ${PKGWILDCARD}

# The 'check' target can be used to check an installed package.
check: uptodate-pkgtools
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_ADMIN} check ${PKGWILDCARD}

# Run pkglint:
lint:
	${_PKG_SILENT}${_PKG_DEBUG}${LOCALBASE}/bin/pkglint

# Create a binary package from an install package using "pkg_tarup"
tarup:
	${_PKG_SILENT}${_PKG_DEBUG} \
	${RM} -f ${PACKAGES}/All/${PKGNAME}${PKG_SUFX}; \
	PKG_DBDIR=${PKG_DBDIR} PKG_SUFX=${PKG_SUFX:S/.//} \
	  PKGREPOSITORY=${PACKAGES}/All \
	  ${LOCALBASE}/bin/pkg_tarup ${PKGNAME}; \
	for CATEGORY in ${CATEGORIES}; do \
	  ${MKDIR} ${PACKAGES}/$$CATEGORY; \
	  cd ${PACKAGES}/$$CATEGORY; \
	  ${RM} -f ${PKGNAME}${PKG_SUFX}; \
	  ${LN} -s ../All/${PKGNAME}${PKG_SUFX}; \
	done

# This is for the use of sites which store distfiles which others may
# fetch - only fetch the distfile if it is allowed to be
# re-distributed freely
mirror-distfiles:
.if !defined(NO_SRC_ON_FTP)
	@${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} fetch NO_IGNORE=yes NO_CHECK_DEPENDS=yes
.endif


# Cleaning up

.if !target(pre-clean)
pre-clean:
	@${DO_NADA}
.endif

.if !target(clean)
clean: pre-clean
.  if (${CLEANDEPENDS} != "NO") && (defined(BUILD_DEPENDS) || defined(DEPENDS))
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} clean-depends
.  endif
	@${ECHO_MSG} "${_PKGSRC_IN}> Cleaning for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -d ${WRKDIR} ]; then					\
		if [ -w ${WRKDIR} ]; then				\
			${RM} -rf ${WRKDIR};				\
		else							\
			${ECHO_MSG} "${_PKGSRC_IN}> ${WRKDIR} not writable, skipping"; \
		fi;							\
	fi
.  ifdef WRKOBJDIR
	-${_PKG_SILENT}${_PKG_DEBUG}					\
	${RMDIR} ${BUILD_DIR} 2>/dev/null;				\
	${RM} -f ${WRKDIR_BASENAME}
.  endif
.endif


.if !target(clean-depends)
clean-depends:
.  if defined(BUILD_DEPENDS) || defined(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for i in `${MAKE} ${MAKEFLAGS} CLEAN_DEPENDS_LIST_TOP=YES clean-depends-list | ${SED} -e 's;\.\./[^ ]*; ;g' | ${TR} -s "[:space:]" "\n" | ${SORT} -u` ;\
	do 								\
		cd ${.CURDIR}/../../$$i &&				\
		${MAKE} ${MAKEFLAGS} CLEANDEPENDS=NO clean;		\
	done
.  endif
.endif


# The clean-depends-list target will produce a list of all 
# BUILD_DEPENDS and DEPENDS packages.  
# As each *DEPENDS package is visited, it is added to the 
# CLEAN_DEPENDS_LIST_SEEN variable.  Once a pkg is in the list
# it will not be visited again.  This prevents traversing the same
# part of the dependency tree multiple times.  Each depending package
# ends up in the list twice.  Once as the relative path from the depending
# package and once as the path from pkgsrc.  Eg, "../../foo/bar foo/bar"
# The "../../foo/bar" version is later removed from the list in the
# clean-depends target.  The remaining bit of redundancy is that some
# packages list their depends as "../bar" instead of "../../foo/bar"
# In this case its possible for a dependency to be visited twice.

.if !target(clean-depends-list)
clean-depends-list:
.  if defined(BUILD_DEPENDS) || defined(DEPENDS)
	@for dir in `${ECHO} ${BUILD_DEPENDS:C/^[^:]*://:C/:.*//}	\
			${DEPENDS:C/^[^:]*://:C/:.*//} |		\
			${TR} '\040' '\012' `; do			\
		case "$$CLEAN_DEPENDS_LIST_SEEN" in			\
		*" "$$dir" "*)  ;; 					\
		*) 							\
			CLEAN_DEPENDS_LIST_SEEN=" $$dir `cd ${.CURDIR} ; cd $$dir && ${MAKE} ${MAKEFLAGS} CLEAN_DEPENDS_LIST_SEEN="$$CLEAN_DEPENDS_LIST_SEEN" CLEAN_DEPENDS_LIST_TOP=NO clean-depends-list`";\
			;;						\
		esac							\
	done ;								\
	if [ "${CLEAN_DEPENDS_LIST_TOP}" != "YES" ]; then		\
		${ECHO} " ${PKGPATH} $$CLEAN_DEPENDS_LIST_SEEN";	\
	else								\
		${ECHO} " $$CLEAN_DEPENDS_LIST_SEEN";			\
	fi
.  else
	@if [ "${CLEAN_DEPENDS_LIST_TOP}" != "YES" ]; then		\
		${ECHO} " ${PKGPATH} $$CLEAN_DEPENDS_LIST_SEEN";	\
	else								\
		${ECHO} " $$CLEAN_DEPENDS_LIST_SEEN";			\
	fi
.  endif
.endif

.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif


.if !target(cleandir)
cleandir: clean
.endif


.if !target(distclean)
distclean: pre-distclean clean
	${_PKG_SILENT}${ECHO_MSG} "${_PKGSRC_IN}> Dist cleaning for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}if [ -d ${_DISTDIR} ]; then		\
		cd ${_DISTDIR} &&					\
		${TEST} -z "${DISTFILES}" || ${RM} -f ${DISTFILES};	\
		${TEST} -z "${PATCHFILES}" || ${RM} -f ${PATCHFILES};	\
	fi
.  if defined(DIST_SUBDIR) && exists(DIST_SUBDIR)
	-${_PKG_SILENT}${_PKG_DEBUG}${RMDIR} ${_DISTDIR}  
.  endif
	-${_PKG_SILENT}${_PKG_DEBUG}${RM} -f README.html
.endif

# Prints out a list of files to fetch (useful to do a batch fetch)

# are we called from bsd.pkg.subdir.mk (i.e. do we scan all dirs anyway)? XXX
.ifdef(_THISDIR_)
RECURSIVE_FETCH_LIST?=	NO
.else
RECURSIVE_FETCH_LIST?=	YES
.endif

.if !target(fetch-list)
fetch-list:
	@${MAKE} ${MAKEFLAGS} fetch-list-recursive RECURSIVE_FETCH_LIST=${RECURSIVE_FETCH_LIST} | ${SORT} -u
.endif # !target(fetch-list)

.if !target(fetch-list-recursive)
fetch-list-recursive:
	@${MAKE} ${MAKEFLAGS} fetch-list-one-pkg
.  if ${RECURSIVE_FETCH_LIST} != "NO"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in `${ECHO} ${BUILD_DEPENDS:C/^[^:]*://:C/:.*//}	\
				  ${DEPENDS:C/^[^:]*://:C/:.*//} |	\
		    ${TR} '\040' '\012' | ${SORT} -u` ; do		\
		cd ${.CURDIR}/$$dir &&					\
		${MAKE} ${MAKEFLAGS} fetch-list-recursive;		\
	done
.  endif # ${RECURSIVE_FETCH_LIST} != "NO"
.endif # !target(fetch-list-recursive)

.if !target(fetch-list-one-pkg)
fetch-list-one-pkg:
	@${MKDIR} ${_DISTDIR}
	@[ -z "${_DISTDIR}" ] || ${ECHO} "${MKDIR} ${_DISTDIR}"
.  if defined(DISTFILES)
.for fetchfile in ${DISTFILES}
	@(cd ${_DISTDIR};						\
	if [ ! -f ${fetchfile} -a ! -f ${fetchfile:T} ]; then		\
		${ECHO} -n "cd ${_DISTDIR} && [ -f ${fetchfile} -o -f ${fetchfile:T} ] || "; \
		for site in "" ${MASTER_SITES_${fetchfile:T}} `${SORTED_MASTER_SITES_CMD}`; do	\
			if [ "X$$site" = X"" ]; then continue; fi; 	\
			${ECHO} -n ${FETCH_CMD} ${FETCH_BEFORE_ARGS} "'"$${site}${fetchfile}"'" "${FETCH_AFTER_ARGS}" '|| '; \
		done;							\
		${ECHO} "${ECHO} ${fetchfile} not fetched";		\
	fi)
.endfor
.  endif # DISTFILES
.  if defined(PATCHFILES)
.for fetchfile in ${PATCHFILE}
	@(cd ${_DISTDIR};						\
	if [ ! -f ${fetchfile} -a ! -f ${fetchfile:T} ]; then		\
		${ECHO} -n "cd ${_DISTDIR} && [ -f ${fetchfile} -o -f ${fetchfile:T} ] || "; \
		for site in ${PATCH_SITES_${fetchfile:T}} `${SORTED_PATCH_SITES_CMD}`; do		\
			${ECHO} -n ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${fetchfile} "${FETCH_AFTER_ARGS}" '|| '; \
		done;							\
		${ECHO} "${ECHO} $${fetchfile} not fetched";		\
	fi)
.endfor
.  endif # defined(PATCHFILES)
.endif # !target(fetch-list-one-pkg)

# Checksumming utilities

.if !target(makesum)
makesum: fetch uptodate-digest
	${_PKG_SILENT}${_PKG_DEBUG}					\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if [ -f ${DISTINFO_FILE} ]; then				\
		${AWK} -- '{print ; exit}' ${DISTINFO_FILE} > $$newfile; \
	else								\
		${ECHO} -n "$$" > $$newfile;				\
		${ECHO} -n "NetBSD" >> $$newfile; 			\
		${ECHO} "$$" >> $$newfile;				\
	fi;								\
	${ECHO} "" >> $$newfile;					\
	cd ${DISTDIR};							\
	for sumfile in "" ${_CKSUMFILES}; do				\
		if [ "X$$sumfile" = "X" ]; then continue; fi;		\
		${DIGEST} ${DIGEST_ALGORITHM} $$sumfile >> $$newfile;	\
		${WC} -c $$sumfile | ${AWK} '{ print "Size (" $$2 ") = " $$1 " bytes" }' >> $$newfile; \
	done;								\
	for ignore in "" ${_IGNOREFILES}; do				\
		if [ "X$$ignore" = "X" ]; then continue; fi;		\
		${ECHO} "${DIGEST_ALGORITHM} ($$ignore) = IGNORE" >> $$newfile; \
	done;								\
	if [ -f ${DISTINFO_FILE} ]; then				\
		${AWK} '$$2 ~ /\(patch-[a-z0-9]+\)/ { print $$0 }' < ${DISTINFO_FILE} >> $$newfile; \
	fi;								\
	if ${CMP} -s $$newfile ${DISTINFO_FILE}; then			\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: distfiles part unchanged.";	\
	else								\
		${MV} $$newfile ${DISTINFO_FILE};			\
	fi
.endif

.if !target(makepatchsum)
makepatchsum mps: uptodate-digest
	${_PKG_SILENT}${_PKG_DEBUG}					\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if [ -f ${DISTINFO_FILE} ]; then					\
		${AWK} '$$2 !~ /\(patch-[a-z0-9]+\)/ { print $$0 }' < ${DISTINFO_FILE} >> $$newfile; \
	else \
		${ECHO} -n "$$" > $$newfile;				\
		${ECHO} -n "NetBSD" >> $$newfile; 			\
		${ECHO} "$$" >> $$newfile;				\
	fi;								\
	if [ -d ${PATCHDIR} ]; then					\
		(cd ${PATCHDIR};					\
		for sumfile in "" patch-*; do				\
			if [ "X$$sumfile" = "X" ]; then continue; fi;	\
			if [ "X$$sumfile" = "Xpatch-*" ]; then break; fi; \
			case $$sumfile in				\
				patch-local-*) ;;			\
				*.orig|*.rej|*~) continue ;;		\
				*)	${ECHO} "${DIGEST_ALGORITHM} ($$sumfile) = `${SED} -e '/\$$NetBSD.*/d' $$sumfile | ${DIGEST} ${DIGEST_ALGORITHM}`" >> $$newfile;; \
			esac;						\
		done);							\
	fi;								\
	if ${CMP} -s $$newfile ${DISTINFO_FILE}; then			\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: patches part unchanged.";	\
	else								\
		${MV} $$newfile ${DISTINFO_FILE};			\
	fi
.endif

# This target is done by invoking a sub-make so that DISTINFO_FILE gets
# re-evaluated after the "makepatchsum" target is made. This can be
# made into:
#makedistinfo mdi: makepatchsum makesum
# once a combined distinfo file exists for all packages
.if !target(makedistinfo)
makedistinfo mdi distinfo: makepatchsum
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} makesum
.endif

.if !target(checksum)
checksum: fetch uptodate-digest
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${DISTINFO_FILE} ]; then				\
		${ECHO_MSG} "=> No checksum file.";			\
	else								\
		(cd ${DISTDIR}; OK="true";				\
		  for file in "" ${_CKSUMFILES}; do			\
		  	if [ "X$$file" = X"" ]; then continue; fi; 	\
			alg=`${AWK} 'NF == 4 && $$2 == "('$$file')" && $$3 == "=" {print $$1;}' ${DISTINFO_FILE}`; \
			if [ "X$$alg" = "X" ]; then			\
				${ECHO_MSG} "=> No checksum recorded for $$file."; \
				OK="false";				\
			else						\
				CKSUM=`${DIGEST} $$alg < $$file`;	\
				CKSUM2=`${AWK} '$$1 == "'$$alg'" && $$2 == "('$$file')"{print $$4;}' ${DISTINFO_FILE}`; \
				if [ "$$CKSUM2" = "IGNORE" ]; then	\
					${ECHO_MSG} "=> Checksum for $$file is set to IGNORE in checksum file even though"; \
					${ECHO_MSG} "   the file is not in the "'$$'"{IGNOREFILES} list."; \
					OK="false";			\
				elif [ "$$CKSUM" = "$$CKSUM2" ]; then	\
					${ECHO_MSG} "=> Checksum OK for $$file."; \
				else					\
					${ECHO_MSG} "=> Checksum mismatch for $$file."; \
					OK="false";			\
				fi;					\
			fi;						\
		  done;							\
		  for file in "" ${_IGNOREFILES}; do			\
		  	if [ "X$$file" = X"" ]; then continue; fi; 	\
			CKSUM2=`${AWK} 'NF == 4 && $$3 == "=" && $$2 == "('$$file')"{print $$4;}' ${DISTINFO_FILE}`; \
			if [ "$$CKSUM2" = "" ]; then			\
				${ECHO_MSG} "=> No checksum recorded for $$file, file is in "'$$'"{IGNOREFILES} list."; \
				OK="false";				\
			elif [ "$$CKSUM2" != "IGNORE" ]; then		\
				${ECHO_MSG} "=> Checksum for $$file is not set to IGNORE in checksum file even though"; \
				${ECHO_MSG} "   the file is in the "'$$'"{IGNOREFILES} list."; \
				OK="false";				\
			fi;						\
		  done;							\
		  if [ "$$OK" != "true" ]; then				\
			${ECHO_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
			${ECHO_MSG} "are up to date.  If you want to override this check, type"; \
			${ECHO_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
			exit 1;						\
		  fi) ;							\
	fi
.endif



# List of sites carrying binary pkgs. Variables "rel" and "arch" are
# replaced with OS release ("1.5", ...) and architecture ("mipsel", ...)
BINPKG_SITE?= \
	ftp://ftp.netbsd.org/pub/NetBSD/packages/$${rel}/$${arch}

# List of flags to pass to pkg_add(8) for bin-install:
BIN_INSTALL_FLAGS?= 	# -v

# Install binary pkg, without strict uptodate-check first
bin-install:
	@found="`${PKG_INFO} -e \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "$$found" != "" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}>  $$found is already installed - perhaps an older version?"; \
		${ECHO_MSG} "*** If so, you may wish to \`\`pkg_delete $$found'' and install"; \
		${ECHO_MSG} "*** this package again by \`\`${MAKE} bin-install'' to upgrade it properly."; \
		${SHCOMMENT} ${ECHO_MSG} "*** or use \`\`${MAKE} bin-update'' to upgrade it and all of its dependencies."; \
		exit 1;							\
	fi
	@if [ -f ${PKGFILE} ] ; then 					\
		${ECHO_MSG} "Installing from binary pkg ${PKGFILE}" ;	\
		${PKG_ADD} ${PKGFILE} ; 				\
	else 				 				\
		rel=`${UNAME} -r | ${SED} 's@\.\([0-9]*\)[\._].*@\.\1@'`; 	\
		arch=`sysctl -n hw.machine_arch`; 			\
		for site in ${BINPKG_SITE} ; do 			\
			${ECHO} Trying `eval ${ECHO} $$site`/All ; 	\
			${SHCOMMENT} ${ECHO} ${SETENV} PKG_PATH="`eval ${ECHO} $$site`/All" ${PKG_ADD} ${BIN_INSTALL_FLAGS} ${PKGNAME}${PKG_SUFX} ; \
			if ${SETENV} PKG_PATH="`eval ${ECHO} $$site`/All" ${PKG_ADD} ${BIN_INSTALL_FLAGS} ${PKGNAME}${PKG_SUFX} ; then \
				${ECHO} "${PKGNAME} successfully installed." ; 			\
				break ; 				\
			fi ; 						\
		done ; 							\
		if ! ${PKG_INFO} -qe ${PKGNAME} ; then 			\
			${SHCOMMENT} Cycle through some FTP server here ;\
			${ECHO_MSG} "Installing from source" ;		\
			${MAKE} ${MAKEFLAGS} package &&			\
			${MAKE} ${MAKEFLAGS} clean ;			\
		fi ; \
	fi


################################################################
# The special package-building targets
# You probably won't need to touch these
################################################################

# Set to "html" by the README.html target to generate HTML code,
# or to "svr4" to print SVR4 (Solaris, ...) short package names, from
# SVR4_PKGNAME variable.
# This variable is passed down via build-depends-list and run-depends-list
PACKAGE_NAME_TYPE?=	name

# Nobody should want to override this unless PKGNAME is simply bogus.

.if !target(package-name)
package-name:
.  if (${PACKAGE_NAME_TYPE} == "html")
	@${ECHO} '<a href="../../${PKGPATH:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}/README.html">${PKGNAME:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}</A>'
.  elif (${PACKAGE_NAME_TYPE} == "svr4")
	@${ECHO} ${SVR4_PKGNAME}
.  else
	@${ECHO} ${PKGNAME}
.  endif # PACKAGE_NAME_TYPE
.endif # !target(package-name)

.if !target(make-readme-html-help)
make-readme-html-help:
	@${ECHO} '${PKGNAME:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}</a>: <TD>'${COMMENT:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g:Q}
.endif # !target(make-readme-html-help)

# Show (recursively) all the packages this package depends on.
# If PACKAGE_DEPENDS_WITH_PATTERNS is set, print as pattern (if possible)
PACKAGE_DEPENDS_WITH_PATTERNS?=true
# To be used (-> true) ONLY if the pkg in question is known to be installed
# (i.e. when calling for pkg_create args, and for fake-pkg)
# Will probably not work with PACKAGE_DEPENDS_WITH_PATTERNS=false ...
PACKAGE_DEPENDS_QUICK?=false
.if !target(run-depends-list)
run-depends-list:
.  for dep in ${DEPENDS}
	@pkg="${dep:C/:.*//}";						\
	dir="${dep:C/[^:]*://}";					\
	cd ${.CURDIR};							\
	if ${PACKAGE_DEPENDS_WITH_PATTERNS}; then			\
		${ECHO} "$$pkg";					\
	else								\
		if cd $$dir 2>/dev/null; then				\
			${MAKE} ${MAKEFLAGS} package-name PACKAGE_NAME_TYPE=${PACKAGE_NAME_TYPE}; \
		else 							\
			${ECHO_MSG} "Warning: \"$$dir\" non-existent -- @pkgdep registration incomplete" >&2; \
		fi;							\
	fi;								\
	if ${PACKAGE_DEPENDS_QUICK} ; then 			\
		${PKG_INFO} -qf "$$pkg" | ${AWK} '/^@pkgdep/ {print $$2}'; \
	else 							\
		if cd $$dir 2>/dev/null; then				\
			${MAKE} ${MAKEFLAGS} run-depends-list PACKAGE_NAME_TYPE=${PACKAGE_NAME_TYPE} PACKAGE_DEPENDS_WITH_PATTERNS=${PACKAGE_DEPENDS_WITH_PATTERNS}; \
		else 							\
			${ECHO_MSG} "Warning: \"$$dir\" non-existent -- @pkgdep registration incomplete" >&2; \
		fi;							\
	fi
.  endfor
.endif # target(run-depends-list)

# Build a package but don't check the package cookie

.if !target(repackage)
repackage: pre-repackage package

pre-repackage:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${PACKAGE_COOKIE}
.endif

# Build a package but don't check the cookie for installation, also don't
# install package cookie

.if !target(package-noinstall)
package-noinstall:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} PACKAGE_NOINSTALL=yes real-package
.endif

################################################################
# Dependency checking
################################################################

.if !target(install-depends)
# Tells whether to halt execution if the object formats differ
FATAL_OBJECT_FMT_SKEW?= yes
WARN_NO_OBJECT_FMT?= yes

install-depends: uptodate-pkgtools
.  if defined(DEPENDS) || defined(BUILD_DEPENDS)
.    if defined(NO_DEPENDS)
	@${DO_NADA}
.    else	# !DEPENDS
.      for dep in ${DEPENDS} ${BUILD_DEPENDS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	pkg="${dep:C/:.*//}";						\
	dir="${dep:C/[^:]*://:C/:.*$//}";				\
	found=`${PKG_INFO} -e "$$pkg" || ${TRUE}`;			\
	if [ "X$$REBUILD_DOWNLEVEL_DEPENDS" != "X" ]; then		\
		pkgname=`cd $$dir ; ${MAKE} ${MAKEFLAGS} show-var VARNAME=PKGNAME`;	\
		if [ "X$$found" != "X" -a "X$$found" != "X$${pkgname}" ]; then		\
			${ECHO_MSG} "ignoring old installed package \"$$found\"";	\
			found="";					\
		fi;							\
	fi;								\
	if [ "$$found" != "" ]; then					\
		instobjfmt=`${PKG_INFO} -B "$$pkg" | ${AWK} '/^OBJECT_FMT/ {print $$2}' | ${HEAD} -1`; \
		if [ "$$instobjfmt" = "" ]; then			\
			if [ "X${WARN_NO_OBJECT_FMT}" != "Xno" ]; then	\
				${ECHO} "WARNING: Unknown object format for installed package $$pkg - continuing"; \
			fi;						\
		elif [ "$$instobjfmt" != "${OBJECT_FMT}" ]; then	\
			${ECHO} "Installed package $$pkg is an $$instobjfmt package."; \
			${ECHO} "You are building an ${OBJECT_FMT} package, which will not inter-operate."; \
			${ECHO} "Please update the $$pkg package to ${OBJECT_FMT}"; \
			if [ "X${FATAL_OBJECT_FMT_SKEW}" != "Xno" ]; then \
				exit 1;					\
			fi;						\
		fi;							\
		if [ `${ECHO} $$found | ${WC} -w` -gt 1 ]; then		\
			${ECHO} '***' "WARNING: Dependency on '$$pkg' expands to several installed packages " ; \
			${ECHO} "    (" `${ECHO} $$found` ")." ; 	\
			${ECHO} "    Please check if this is really intended!" ; \
		else 							\
			${ECHO_MSG} "${_PKGSRC_IN}> Required installed package $$pkg: $${found} found"; \
		fi ; 							\
	else								\
		${ECHO_MSG} "${_PKGSRC_IN}> Required package $$pkg: NOT found"; \
		target=${DEPENDS_TARGET};				\
		${ECHO_MSG} "${_PKGSRC_IN}> Verifying $$target for $$dir"; 	\
		if [ ! -d $$dir ]; then					\
			${ECHO_MSG} "=> No directory for $$dir.  Skipping.."; \
		else							\
			cd $$dir ;					\
			${MAKE} ${MAKEFLAGS} $$target _PKGSRC_DEPS=", ${PKGNAME}${_PKGSRC_DEPS}"; \
			${ECHO_MSG} "${_PKGSRC_IN}> Returning to build of ${PKGNAME}"; \
		fi;							\
	fi
.      endfor	# DEPENDS
.    endif	# !NO_DEPENDS
.  endif	# DEPENDS

.endif

real-fetch: check-depends
.if !target(check-depends)
check-depends:
.  if (defined(DEPENDS) || defined(BUILD_DEPENDS)) && \
      !defined(NO_DEPENDS) && !defined(NO_CHECK_DEPENDS) && !exists(${EXTRACT_COOKIE})
	${_PKG_SILENT}${_PKG_DEBUG}\
	${ECHO_MSG} "${_PKGSRC_IN}> Validating dependencies for ${PKGNAME}" ; \
	${MAKE} ${MAKEFLAGS} DEPENDS_TARGET=check-depends ECHO_MSG=${TRUE:Q} IGNORE_FAIL=1 _DEPENDS_TARGET_OVERRIDE=1 install-depends || \
		{ ${ECHO_MSG} "${_PKGSRC_IN}> ${PKGNAME} cannot build necessary dependencies."; ${FALSE}; }
.  endif
.endif

.if !target(build-depends-list)
build-depends-list:
.  for dir in ${BUILD_DEPENDS} ${DEPENDS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${dir:C/^[^:]*://:C/:.*//};					\
	${MAKE} ${MAKEFLAGS} package-name build-depends-list PACKAGE_NAME_TYPE=${PACKAGE_NAME_TYPE}
.  endfor
.endif

# If PACKAGES is set to the default (../../pkgsrc/packages), the current
# ${MACHINE_ARCH} and "release" (uname -r) will be used. Otherwise a directory
# structure of ...pkgsrc/packages/`uname -r`/${MACHINE_ARCH} is assumed.
# The PKG_URL is set from FTP_PKG_URL_* or CDROM_PKG_URL_*, depending on
# the target used to generate the README.html file.
.if !target(binpkg-list)
binpkg-list:
	@if [ -e ${PACKAGES} ]; then					\
		cd ${PACKAGES};						\
		case ${.CURDIR} in					\
		*/pkgsrc/packages)					\
			for pkg in ${PKGREPOSITORYSUBDIR}/${PKGWILDCARD}${PKG_SUFX} ; \
			do 						\
				if [ -f "$$pkg" ] ; then		\
					pkgname=`${ECHO} $$pkg | ${SED} 's@.*/@@'`; \
					${ECHO} "<TR><TD>${MACHINE_ARCH}:<TD><a href=\"${PKG_URL}/$$pkg\">$$pkgname</a><TD>(${OPSYS} ${OS_VERSION})"; \
				fi ;					\
			done ; 						\
			;;						\
		*)							\
			cd ${PACKAGES}/../..;				\
			for i in [1-9].*/*; do  			\
				if cd ${PACKAGES}/../../$$i/${PKGREPOSITORYSUBDIR} 2>/dev/null; then \
					for j in ${PKGWILDCARD}${PKG_SUFX}; \
					do 				\
						if [ -f "$$j" ]; then	\
							${ECHO} $$i/$$j;\
						fi;			\
					done; 				\
				fi; 					\
			done | ${AWK} -F/ '				\
				{					\
					release = $$1;			\
					arch = $$2; 			\
					pkg = $$3;			\
					gsub("\.tgz","", pkg);		\
					if (arch != "m68k" && arch != "mipsel") { \
						if (arch in urls)	\
							urls[arch "/" pkg "/" release] = "<a href=\"${PKG_URL}/" release "/" arch "/${PKGREPOSITORYSUBDIR}/" pkg "${PKG_SUFX}\">" pkg "</a>, " urls[arch]; \
						else			\
							urls[arch "/" pkg "/" release] = "<a href=\"${PKG_URL}/" release "/" arch "/${PKGREPOSITORYSUBDIR}/" pkg "${PKG_SUFX}\">" pkg "</a> "; \
					}				\
				} 					\
				END { 					\
					for (av in urls) {		\
						split(av, ava, "/");	\
						arch=ava[1];		\
						pkg=ava[2];		\
						release=ava[3];		\
						print "<TR><TD>" arch ":<TD>" urls[av] "<TD>(${OPSYS} " release ")"; \
					}				\
				}' | ${SORT}				\
			;;						\
		esac;							\
	fi
.endif

################################################################
# Everything after here are internal targets and really
# shouldn't be touched by anybody but the release engineers.
################################################################

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|package-path|installation-prefix|comment| \
#  description-file|maintainer|categories|build deps|run deps|for arch
#
.if !target(describe)
describe:
	@${ECHO} -n "${PKGNAME}|${.CURDIR}|";				\
	${ECHO} -n "${PREFIX}|";					\
	${ECHO} -n ${COMMENT:Q};					\
	if [ -f ${DESCR_SRC} ]; then					\
		${ECHO} -n "|${DESCR_SRC}";				\
	else								\
		${ECHO} -n "|/dev/null";				\
	fi;								\
	${ECHO} -n "|${MAINTAINER}|${CATEGORIES}|";			\
	case "A${BUILD_DEPENDS}B${DEPENDS}C" in	\
		ABC) ;;							\
		*) cd ${.CURDIR} && ${ECHO} -n `${MAKE} ${MAKEFLAGS} build-depends-list | ${SORT} -u`;; \
	esac;								\
	${ECHO} -n "|";							\
	if [ "${DEPENDS}" != "" ]; then				\
		cd ${.CURDIR} && ${ECHO} -n `${MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`; \
	fi;								\
	${ECHO} -n "|";							\
	if [ "${ONLY_FOR_ARCHS}" = "" ]; then				\
		${ECHO} -n "any";					\
	else								\
		${ECHO} -n "${ONLY_FOR_ARCHS}";				\
	fi;								\
	${ECHO} -n "|";							\
	if [ "${NOT_FOR_OPSYS}" = "" ]; then				\
		${ECHO} -n "any";					\
	else								\
		${ECHO} -n "not ${NOT_FOR_OPSYS}";			\
	fi;								\
	${ECHO} ""
.endif

.if !target(readmes)
readmes:	readme
.endif

# This target is used to generate README.html files
.if !target(readme)
FTP_PKG_URL_HOST?=	ftp://ftp.netbsd.org
FTP_PKG_URL_DIR?=	/pub/NetBSD/packages

readme:
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} README.html PKG_URL=${FTP_PKG_URL_HOST}${FTP_PKG_URL_DIR}
.endif

# This target is used to generate README.html files, very like "readme"
# However, a different target was used for ease of use.
.if !target(cdrom-readme)
CDROM_PKG_URL_HOST?=	file://localhost
CDROM_PKG_URL_DIR?=	/usr/pkgsrc/packages

cdrom-readme:
	@cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} README.html PKG_URL=${CDROM_PKG_URL_HOST}${CDROM_PKG_URL_DIR}
.endif

README_NAME=	${TEMPLATES}/README.pkg

# set up the correct license information as a sed expression
.ifdef LICENSE
SED_LICENSE_EXPR=       -e 's|%%LICENSE%%|<p>Please note that this package has a ${LICENSE} license.</p>|'
.else
SED_LICENSE_EXPR=       -e 's|%%LICENSE%%||'
.endif

# set up the "more info URL" information as a sed expression
.ifdef HOMEPAGE
SED_HOMEPAGE_EXPR=       -e 's|%%HOMEPAGE%%|<p>This package has a home page at <a HREF="${HOMEPAGE}">${HOMEPAGE}</a>.</p>|'
.else
SED_HOMEPAGE_EXPR=       -e 's|%%HOMEPAGE%%||'
.endif

show-vulnerabilities:
	@if [ -f ${DISTDIR}/vulnerabilities ]; then			\
		${AWK} '/^${PKGBASE}/ { print $$0 }' ${DISTDIR}/vulnerabilities; \
	else								\
		${ECHO} "No vulnerabilities list found.";		\
	fi

show-vulnerabilities-html:
	@if [ -f ${DISTDIR}/vulnerabilities ]; then			\
		${AWK} '/^${PKGBASE}/ { gsub("\<", "\\&lt;", $$1);	\
			 gsub("\>", "\\&gt;", $$1);			\
			 printf("<STRONG><LI>%s has a %s exploit (see <a href=\"%s\">%s</a> for more details)</STRONG>\n", $$1, $$2, $$3, $$3) }' \
			${DISTDIR}/vulnerabilities;			\
	fi


.PHONY: README.html
README.html: .PRECIOUS
	@${MAKE} ${MAKEFLAGS} build-depends-list PACKAGE_NAME_TYPE=html | ${SORT} -u >> $@.tmp1
	@[ -s $@.tmp1 ] || ${ECHO} "<I>(none)</I>" >> $@.tmp1
	@${MAKE} ${MAKEFLAGS} run-depends-list PACKAGE_NAME_TYPE=html | ${SORT} -u >> $@.tmp2
	@[ -s $@.tmp2 ] || ${ECHO} "<I>(none)</I>" >> $@.tmp2
	@${MAKE} ${MAKEFLAGS} binpkg-list  >> $@.tmp4
	@[ -s $@.tmp4 ] || ${ECHO} "<TR><TD><I>(no precompiled binaries available)</I>" >> $@.tmp4
	@${MAKE} ${MAKEFLAGS} show-vulnerabilities-html >> $@.tmp5
	@[ -s $@.tmp5 ] || ${ECHO} "<I>(no vulnerabilities known)</I>" >> $@.tmp5
	@${LS} -l ${DISTDIR}/vulnerabilities 2>&1 | ${AWK} 'NF > 7 { printf("at %s %s %s\n", $$6, $$7, $$8) }' >> $@.tmp6
	@[ -s $@.tmp6 ] || ${ECHO} "<TR><TD><I>(no vulnerabilities list available)</I>" >> $@.tmp6
	@${SED} -e 's|%%PORT%%|${PKGPATH}|g'				\
		-e 's|%%PKG%%|${PKGNAME}|'				\
		${SED_LICENSE_EXPR}					\
		${SED_HOMEPAGE_EXPR}					\
		-e '/%%VULNERABILITIES%%/r $@.tmp5'			\
		-e '/%%VULNERABILITIES%%/d'				\
		-e '/%%VULDATE%%/r $@.tmp6'				\
		-e '/%%VULDATE%%/d'					\
		-e "s/%%COMMENT%%/${COMMENT:S|/|\/|g:Q}/"		\
		-e '/%%BUILD_DEPENDS%%/r $@.tmp1'			\
		-e '/%%BUILD_DEPENDS%%/d'				\
		-e '/%%RUN_DEPENDS%%/r $@.tmp2'				\
		-e '/%%RUN_DEPENDS%%/d'					\
		-e '/%%BIN_PKGS%%/r $@.tmp4'				\
		-e '/%%BIN_PKGS%%/d'					\
		${README_NAME} >> $@.tmp
	@${CMP} -s $@.tmp $@ || 					\
		{ ${ECHO_MSG} "${_PKGSRC_IN}> Creating README.html for ${_THISDIR_}${PKGNAME}"; \
		${MV} -f $@.tmp $@; }
	@${RM} -f $@.tmp $@.tmp1 $@.tmp2 $@.tmp4 $@.tmp5 $@.tmp6

.if !target(show-pkgtools-version)
show-pkgtools-version:
	@${ECHO} ${PKGTOOLS_VERSION}
.endif

# convenience target, to display make variables from command line
# i.e. "make show-var VARNAME=var", will print var's value
show-var:
	@${ECHO} ${${VARNAME}:Q}

# enhanced version of target above, to display multiple variables
show-vars:
.for VARNAME in ${VARNAMES}
	@${ECHO} ${${VARNAME}:Q}
.endfor

.if !target(print-build-depends-list)
print-build-depends-list:
.  if defined(BUILD_DEPENDS) || defined(DEPENDS)
	@${ECHO} -n 'This package requires package(s) "'
	@${ECHO} -n `${MAKE} ${MAKEFLAGS} build-depends-list | ${SORT} -u`
	@${ECHO} '" to build.'
.  endif
.endif

.if !target(print-run-depends-list)
print-run-depends-list:
.  if defined(DEPENDS)
	@${ECHO} -n 'This package requires package(s) "'
	@${ECHO} -n `${MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`
	@${ECHO} '" to run.'
.  endif
.endif

.if !target(show-license)
show-license show-licence:
	@if [ "${LICENSE}" != "" ]; then				\
		if [ -e ${PKGSRCDIR}/licenses/${LICENSE} ]; then	\
			${CAT} ${PKGSRCDIR}/licenses/${LICENSE};	\
		else							\
			${ECHO} "Generic ${LICENSE} information not available"; \
			${ECHO} "See the package description (pkg_info -d ${PKGNAME}) for more information."; \
		fi							\
	fi
.endif

# Stat all the files of one pkg and sum the sizes up. 
# 
# XXX This is intended to be run before pkg_create is called, so the
# existence of ${PLIST} can be assumed.
print-pkg-size-this:
	@${SHCOMMENT} "This pkg's files" ;				\
	${AWK} 'BEGIN { base = "${PREFIX}/" }				\
		/^@cwd/ { base = $$2 "/" }				\
		/^@ignore/ { next }					\
		NF == 1 { print base $$1 }'				\
		<${PLIST} 						\
	| ${SORT} -u							\
	| ${SED} -e 's, ,\\ ,g'						\
	| ${XARGS} ${LS} -ld						\
	| ${AWK} 'BEGIN { print("0 "); }				\
		  { print($$5, " + "); }				\
		  END { print("p"); }'					\
	| ${DC}

# Sizes of required pkgs (only)
# 
# XXX This is intended to be run before pkg_create is called, so the
# dependencies are all installed. 
print-pkg-size-depends:
	@${MAKE} ${MAKEFLAGS} run-depends-list PACKAGE_DEPENDS_QUICK=true \
	| ${XARGS} -n 1 ${SETENV} ${PKG_INFO} -e			\
	| ${SORT} -u							\
	| ${XARGS} -n 256 ${SETENV} ${PKG_INFO} -qs			\
	| ${AWK} -- 'BEGIN { print("0 "); }				\
		/^[0-9]+$$/ { print($$1, " + "); }			\
		END { print("p"); }'					\
	| ${DC}


###
### Automatic PLIST generation
###  - files & symlinks first
###  - @exec/@unexec calls are added for info files
###  - @dirrm statements last
###  - empty directories are handled properly
###  - dirs from mtree files are excluded
###
### Usage:
###  - make install
###  - make print-PLIST | brain >PLIST
###

# Common (system) directories not to generate @dirrm statements for
# Reads MTREE_FILE and extracts a list of sed commands that will
# sort out which directories NOT to include into the PLIST @dirrm list
.if make(print-PLIST)
COMMON_DIRS!= 	${AWK} 'BEGIN  { 				\
			i=0; 					\
			stack[i]="${PREFIX}" ; 			\
			cwd=""; 				\
		} 						\
		! ( /^\// || /^\#/ || /^$$/ ) { 		\
			if ( $$1 == ".." ){ 			\
				i=i-1;				\
				cwd = stack[i];			\
			} else if ( $$1 == "." ){ 		\
			} else {				\
				stack[i] = cwd ;		\
				if ( i == 0 ){ 			\
					cwd = $$1 ; 		\
				} else {			\
					cwd = cwd "\\\\/" $$1 ; \
				} 				\
				print "-e \"/^" cwd "$$$$/d\"";	\
				i=i+1 ; 			\
			} 					\
		} 						\
	' <${MTREE_FILE}
.endif


# scan $PREFIX for any files/dirs modified since the package was extracted
# will emit "@exec mkdir"-statements for empty directories
# XXX will fail for data files that were copied using tar (e.g. emacs)!
# XXX should check $LOCALBASE and $X11BASE, and add @cwd statements

.if !target(print-PLIST)
print-PLIST:
	${_PKG_SILENT}${_PKG_DEBUG}\
	${ECHO} '@comment $$'NetBSD'$$'
	${_PKG_SILENT}${_PKG_DEBUG}\
	shlib_type=`${MAKE} ${MAKEFLAGS} show-shlib-type`;		\
	case $$shlib_type in 						\
	"a.out")	genlinks=1 ;;					\
	*)		genlinks=0 ;;					\
	esac;								\
	${FIND} ${PREFIX}/. -newer ${EXTRACT_COOKIE} \! -type d 	\
	 | ${SED}							\
		-e  's@${PREFIX}/./@@' 					\
		-e  's@${OPSYS}@\$${OPSYS}@' 				\
		-e  's@${OS_VERSION:S/./\./}@\$${OS_VERSION}@'		\
		-e  's@${MACHINE_ARCH}@\$${MACHINE_ARCH}@' 		\
		-e  's@${MACHINE_GNU_ARCH}@\$${MACHINE_GNU_ARCH}@'	\
		-e  's@${MACHINE_GNU_PLATFORM}@\$${MACHINE_GNU_PLATFORM}@' \
		-e  's@${LOWER_VENDOR}@\$${LOWER_VENDOR}@' 		\
		-e  's@${LOWER_OPSYS}@\$${LOWER_OPSYS}@' 		\
		-e  's@${PKGNAME}@\$${PKGNAME}@' 			\
	 | ( ${GREP} -v emul/linux/proc || ${TRUE} )			\
	 | ${SORT}							\
	 | ${AWK} '							\
		/^@/ { print $$0; next }				\
		/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+\.[0-9]+$$/ { 	\
			print $$0;					\
			sub("\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			sub("\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			sub("\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			next;						\
		}							\
		/.*\/lib[^\/]+\.so\.[0-9]+\.[0-9]+$$/ { 		\
			print $$0;					\
			sub("\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			sub("\.[0-9]+$$", "");				\
			if ('$$genlinks') print $$0;			\
			next;						\
		}							\
		{ 							\
		  if (/\.info$$/) {					\
		    print "\@unexec install-info --delete --info-dir=%D/info %D/" $$0; \
		    print $$0;						\
		    print "\@exec install-info --info-dir=%D/info %D/" $$0; \
		  } else if (!/^info\/dir$$/) {				\
		    print $$0;						\
		  }							\
		}'
	${_PKG_SILENT}${_PKG_DEBUG}\
	for i in `${FIND} ${PREFIX}/. -newer ${EXTRACT_COOKIE} -type d	\
			| ${SED}					\
				-e s@${PREFIX}/./@@			\
				-e '/^${PREFIX:S/\//\\\//g}\/.$$/d'	\
			| ${SORT} -r | ${SED} ${COMMON_DIRS}` ;		\
	do								\
		if [ `${LS} -la ${PREFIX}/$$i | ${WC} -l` = 3 ]; then	\
			${ECHO} @exec ${MKDIR} %D/$$i ;		\
		fi ;							\
		${ECHO} @dirrm $$i ;					\
	done								\
	| ${SED}							\
		-e  s@${OPSYS}@\$${OPSYS}@ 				\
		-e  s@${OS_VERSION}@\$${OS_VERSION}@ 			\
		-e  s@${MACHINE_ARCH}@\$${MACHINE_ARCH}@ 		\
		-e  s@${MACHINE_GNU_ARCH}@\$${MACHINE_GNU_ARCH}@	\
		-e  s@${MACHINE_GNU_PLATFORM}@\$${MACHINE_GNU_PLATFORM}@ \
		-e  s@${LOWER_VENDOR}@\$${LOWER_VENDOR}@ 		\
		-e  s@${LOWER_OPSYS}@\$${LOWER_OPSYS}@ 			\
		-e  s@${PKGNAME}@\$${PKGNAME}@ 				\
	 | ${GREP} -v emul/linux/proc || ${TRUE}
.endif # target(print-PLIST)


# Fake installation of package so that user can pkg_delete it later.
# Also, make sure that an installed package is recognized correctly in
# accordance to the @pkgdep directive in the packing lists

.if !target(fake-pkg)
fake-pkg: ${PLIST} ${DESCR} ${MESSAGE}
	${_PKG_SILENT}${_PKG_DEBUG}\
	if [ ! -f ${PLIST} -o ! -f ${DESCR} ]; then \
		${ECHO} "** Missing package files for ${PKGNAME} - installation not recorded."; \
		exit 1;							\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}\
	if [ ! -d ${PKG_DBDIR} ]; then	\
		${RM} -f ${PKG_DBDIR};					\
		${MKDIR} ${PKG_DBDIR};					\
	fi
.  if defined(FORCE_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_DELETE} -O ${PKGNAME}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -rf ${PKG_DBDIR}/${PKGNAME}
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${BUILD_VERSION_FILE} ${BUILD_INFO_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${SIZE_PKG_FILE} ${SIZE_ALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}\
	files="";				\
	for f in ${.CURDIR}/Makefile ${FILESDIR}/* ${PKGDIR}/*; do	\
		if [ -f $$f ]; then					\
			files="$$files $$f";				\
		fi;							\
	done;								\
	if [ -f ${DISTINFO_FILE} ]; then				\
		for f in `${AWK} 'NF == 4 && $$3 == "=" { gsub("[()]", "", $$2); print $$2 }' < ${DISTINFO_FILE}`; do \
			if [ -f ${PATCHDIR}/$$f ]; then			\
				files="$$files ${PATCHDIR}/$$f";	\
			fi;						\
		done;							\
	fi;								\
	if [ -d ${PATCHDIR} ]; then					\
		for f in ${PATCHDIR}/patch-*; do			\
			case $$f in					\
			*.orig|*.rej|*~) ;;				\
			${PATCHDIR}/patch-local-*)			\
				files="$$files $$f" ;;			\
			esac;						\
		done;							\
	fi;								\
	${GREP} '\$$NetBSD' $$files | ${SED} -e 's|^${PKGSRCDIR}/||' > ${BUILD_VERSION_FILE};
.  for def in ${BUILD_DEFS}
	@${ECHO} ${def}=	${${def}:Q} | ${SED} -e 's|^PATH=[^ 	]*|PATH=...|' >> ${BUILD_INFO_FILE}
.  endfor
	@if ${CC} --version >/dev/null 2>&1; then \
	  ${ECHO} "CC=	${CC}-`${CC} --version`" >> ${BUILD_INFO_FILE}; \
	fi
.  ifdef USE_PERL5
	@${ECHO} "PERL=	`${PERL5} --version 2>/dev/null | ${GREP} 'This is perl'`" >> ${BUILD_INFO_FILE}
.  endif
.  ifdef USE_GMAKE
	@${ECHO} "GMAKE=	`${GMAKE} --version | ${GREP} version`" >> ${BUILD_INFO_FILE}
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "_PKGTOOLS_VER=${PKGTOOLS_VERSION}" >> ${BUILD_INFO_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	size_this=`${MAKE} ${MAKEFLAGS} print-pkg-size-this`;		\
	size_depends=`${MAKE} ${MAKEFLAGS} print-pkg-size-depends`;	\
	${ECHO} $$size_this >${SIZE_PKG_FILE};				\
	${ECHO} $$size_this $$size_depends + p | ${DC} >${SIZE_ALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -d ${PKG_DBDIR}/${PKGNAME} ]; then			\
		${ECHO_MSG} "${_PKGSRC_IN}> Registering installation for ${PKGNAME}"; \
		${MKDIR} ${PKG_DBDIR}/${PKGNAME};			\
		${PKG_CREATE} ${PKG_ARGS_INSTALL} -O ${PKGFILE} > ${PKG_DBDIR}/${PKGNAME}/+CONTENTS; \
		${CP} ${DESCR} ${PKG_DBDIR}/${PKGNAME}/+DESC;		\
		${ECHO} ${COMMENT:Q} > ${PKG_DBDIR}/${PKGNAME}/+COMMENT; \
		${CP} ${BUILD_VERSION_FILE} ${PKG_DBDIR}/${PKGNAME}/+BUILD_VERSION; \
		${CP} ${BUILD_INFO_FILE} ${PKG_DBDIR}/${PKGNAME}/+BUILD_INFO; \
		if ${TEST} -e ${SIZE_PKG_FILE}; then 			\
			${CP} ${SIZE_PKG_FILE} ${PKG_DBDIR}/${PKGNAME}/+SIZE_PKG; \
		fi ; 							\
		if ${TEST} -e ${SIZE_ALL_FILE}; then 			\
			${CP} ${SIZE_ALL_FILE} ${PKG_DBDIR}/${PKGNAME}/+SIZE_ALL; \
		fi ; 							\
		if [ -n "${INSTALL_FILE}" ]; then			\
			if ${TEST} -e ${INSTALL_FILE}; then		\
				${CP} ${INSTALL_FILE} ${PKG_DBDIR}/${PKGNAME}/+INSTALL; \
			fi;						\
		fi;							\
		if [ -n "${DEINSTALL_FILE}" ]; then			\
			if ${TEST} -e ${DEINSTALL_FILE}; then		\
				${CP} ${DEINSTALL_FILE} ${PKG_DBDIR}/${PKGNAME}/+DEINSTALL; \
			fi;						\
		fi;							\
		if [ -n "${MESSAGE}" ]; then				\
			if ${TEST} -e ${MESSAGE}; then			\
				${CP} ${MESSAGE} ${PKG_DBDIR}/${PKGNAME}/+DISPLAY; \
			fi;						\
		fi;							\
		list="`${MAKE} ${MAKEFLAGS} run-depends-list PACKAGE_DEPENDS_QUICK=true ECHO_MSG=${TRUE} | ${SORT} -u`" ; \
		for dep in $$list; do \
			realdep="`${PKG_INFO} -e \"$$dep\" || ${TRUE}`" ; \
			if [ `${ECHO} $$realdep | ${WC} -w` -gt 1 ]; then \
				${ECHO} '***' "WARNING: '$$dep' expands to several installed packages " ; \
				${ECHO} "    (" `${ECHO} $$realdep` ")." ; \
				${ECHO} "    Please check if this is really intended!" ; \
				continue ; 				\
			fi ; 						\
		done ; 							\
		for realdep in `${ECHO} $$list | ${XARGS} -n 1 ${SETENV} ${PKG_INFO} -e | ${SORT} -u`; do \
			if ${TEST} -z "$$realdep"; then			\
				${ECHO} "$$dep not installed - dependency NOT registered" ; \
			elif [ -d ${PKG_DBDIR}/$$realdep ]; then	\
				if ${TEST} ! -e ${PKG_DBDIR}/$$realdep/+REQUIRED_BY; then \
					${TOUCH} ${PKG_DBDIR}/$$realdep/+REQUIRED_BY; \
				fi; 					\
				${AWK} 'BEGIN { found = 0; } 		\
					$$0 == "${PKGNAME}" { found = 1; } \
					{ print $$0; } 			\
					END { if (!found) { printf("%s\n", "${PKGNAME}"); }}' \
					< ${PKG_DBDIR}/$$realdep/+REQUIRED_BY > ${PKG_DBDIR}/$$realdep/reqby.$$$$; \
				${MV} ${PKG_DBDIR}/$$realdep/reqby.$$$$ ${PKG_DBDIR}/$$realdep/+REQUIRED_BY; \
				${ECHO} "${PKGNAME} requires installed package $$realdep"; \
			fi;						\
		done;							\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${DISTDIR}/vulnerabilities ]; then			\
		allvul="`${AWK} '/#.*/ { next } NF > 0 { cmd = sprintf(\"${PKG_INFO} -e \\\"%s\\\"\", $$1); system(cmd) }' ${DISTDIR}/vulnerabilities`"; \
		for vul in "" $$allvul; do				\
			if [ "X$$vul" = "X" ]; then continue; fi;	\
			if [ "$$vul" = "${PKGNAME}" ]; then		\
				${ECHO_MSG} '*** WARNING: This package (${PKGNAME}) has a security vulnerability ***'; \
				${ECHO_MSG} "`${MAKE} show-vulnerabilities`"; \
				${ECHO_MSG} '*** WARNING: You are strongly advised to deinstall ${PKGNAME} now ***'; \
			fi;						\
		done;							\
	fi
.endif

# Depend is generally meaningless for arbitrary packages, but if someone wants
# one they can override this.  This is just to catch people who've gotten into
# the habit of typing `${MAKE} depend all install' as a matter of course.
#
.if !target(depend)
depend:
.endif

# Same goes for tags
.if !target(tags)
tags:
.endif

# if automatic manual page compression is done by the package according
# to MANZ's value, set MANCOMPRESSED if MANZ is set
.if defined(MANCOMPRESSED_IF_MANZ) && defined(MANZ)
MANCOMPRESSED=	yes
MAKE_ENV+=	MANZ="${MANZ}"
.endif

# generate ${PLIST} from ${PLIST_SRC} by:
# - fixing list of man-pages according to MANCOMPRESSED/MANZ
#   (we don't take any notice of MANCOMPRESSED as many packages have .gz
#   pages in PLIST even when they install manpages without compressing them)
# - substituting by ${PLIST_SUBST}
# - adding files and appropriate rmdir statements for perl5 modules if
#   PERL5_PACKLIST is defined
# - adding symlinks for shared libs (ELF) or ldconfig calls (a.out).

.if ${_OPSYS_HAS_MANZ} == "yes"
.  ifdef MANZ
_MANZ_EXPRESSION= -e 's|\(^\([^@/]*/\)*man/\([^/]*/\)\{0,1\}man[1-9ln]/.*[1-9ln]$$\)|\1.gz|' \
		-e 's|\(^\([^@/]*/\)*man/\([^/]*/\)\{0,1\}cat[1-9ln]/.*0$$\)|\1.gz|'
.  else
_MANZ_EXPRESSION= -e 's|\(^\([^@/]*/\)*man/\([^/]*/\)\{0,1\}man[1-9ln]/.*[1-9ln]\)\.gz$$|\1|' \
		-e 's|\(^\([^@/]*/\)*man/\([^/]*/\)\{0,1\}cat[1-9ln]/.*0\)\.gz$$|\1|'
.  endif # MANZ
_MANZ_NAWK_CMD=
.else
_MANZ_EXPRESSION= 
.  ifdef MANZ
_MANZ_NAWK_CMD=	${AWK} '/^([^\/]*\/)*man\/([^\/]*\/)?man[1-9ln]\/.*[1-9ln]\.gz$$/ { \
		$$0 = sprintf("%s.gz", $$0);				\
	}								\
	/^([^\/]*\/)*man\/([^\/]*\/)?cat[1-9ln]\/.*0\.gz$$/ {	\
		$$0 = sprintf("%s.gz", $$0);				\
	}								\
	{ print $$0; }' |
.  else
_MANZ_NAWK_CMD=	${AWK} '/^([^\/]*\/)*man\/([^\/]*\/)?man[1-9ln]\/.*[1-9ln]\.gz$$/ { \
		$$0 = substr($$0, 1, length($$0) - 3);			\
	}								\
	/^([^\/]*\/)*man\/([^\/]*\/)?cat[1-9ln]\/.*0\.gz$$/ {	\
		$$0 = substr($$0, 1, length($$0) - 3);			\
	}								\
	{ print $$0; }' |
.  endif # MANZ
.endif

.if defined(USE_IMAKE) && ${_PREFORMATTED_MAN_DIR} == "man"
_IMAKE_MAN_CMD=	${AWK} '/^([^\/]*\/)*man\/([^\/]*\/)?cat[1-9ln]\/.*0(\.gz)?$$/ { \
	sect = $$0; n = match(sect, "/cat[1-9ln]");			\
	sect = sprintf(".%s", substr(sect, n + 4, 1));			\
	s = $$0; sub("/cat", "/man", s); sub("\.0(\.gz)?$$", sect, s);	\
	if (match($$0, "\.gz$$") > 0) { ext = ".gz";} else { ext = "";} \
	$$0 = sprintf("%s%s", s, ext);					\
	} { print $$0; }' |
.  else
_IMAKE_MAN_CMD=
.endif # USE_IMAKE

.if defined(PERL5_PACKLIST)
PERL5_COMMENT=		( ${ECHO} "@comment The following lines are automatically generated"; \
	${ECHO} "@comment from the installed .packlist files." )
PERL5_PACKLIST_FILES=	( ${CAT} ${PERL5_PACKLIST}; for f in ${PERL5_PACKLIST}; do [ ! -f $$f ] || ${ECHO} $$f; done ) \
	| ${SED} -e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,," \
	| ${SORT} -u
PERL5_PACKLIST_DIRS=	( ${CAT} ${PERL5_PACKLIST}; for f in ${PERL5_PACKLIST}; do [ ! -f $$f ] || ${ECHO} $$f; done ) \
	| ${SED} -e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,," \
		-e "s,^,@unexec ${RMDIR} -p %D/," \
		-e "s,/[^/]*$$, 2>/dev/null || true," \
	| ${SORT} -ur
PERL5_GENERATE_PLIST=	${PERL5_COMMENT}; \
			${PERL5_PACKLIST_FILES}; \
			${PERL5_PACKLIST_DIRS}
.else
PERL5_GENERATE_PLIST=	${TRUE}
.endif

message: ${MESSAGE}
.ifdef MESSAGE
${MESSAGE}: ${MESSAGE_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -z "${MESSAGE_SRC}" ]; then				\
		${ECHO} "${MESSAGE_SRC} not found.";			\
		${ECHO} "Please set MESSAGE_SRC correctly.";		\
	else								\
		${CAT} ${MESSAGE_SRC} |					\
			${SED} ${MESSAGE_SUBST_SED}			\
			> ${MESSAGE};					\
	fi
.endif

plist: ${PLIST}
${PLIST}: ${PLIST_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	{ ${CAT} ${PLIST_SRC};						\
	  ${PERL5_GENERATE_PLIST}; } | 					\
		${_MANZ_NAWK_CMD} 					\
		${_IMAKE_MAN_CMD} 					\
		${SED} 	${_MANZ_EXPRESSION}				\
			${PLIST_SUBST:S/=/}!/:S/$/!g/:S/^/ -e s!\\\${/}	\
		> ${PLIST}; 						\
	  ${MAKE} ${MAKEFLAGS} do-shlib-handling			\
		SHLIB_PLIST_MODE=1 ;					\

# generate ${DESCR} from ${DESCR_SRC} by:
# - Appending the homepage URL, if any

descr: ${DESCR}
${DESCR}: ${DESCR_SRC}
	@${CAT} ${DESCR_SRC} 	 >${DESCR}
.if defined(HOMEPAGE)
	@\
	${ECHO}			>>${DESCR} ; \
	${ECHO} "Homepage:"	>>${DESCR} ; \
	${ECHO} '${HOMEPAGE}'	>>${DESCR}	
.endif


#
# For bulk build targets (bulk-install, bulk-package), the
# BATCH variable must be set in /etc/mk.conf:
#
.if defined(BATCH)
.  include "../../mk/bulk/bsd.bulk-pkg.mk"
.endif
