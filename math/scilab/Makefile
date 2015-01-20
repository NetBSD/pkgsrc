# $NetBSD: Makefile,v 1.95 2015/01/20 14:24:36 jaapb Exp $
#

DISTNAME=	${SCIBASE}-src
PKGREVISION=	14
PKGNAME=	${SCIBASE}
CATEGORIES=	math
MASTER_SITES=	http://www.scilab.org/download/4.1/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.scilab.org/
COMMENT=	High-level scientific math programming environment with graphics

MAKE_JOBS_SAFE=	no

SCIBASE=	scilab-4.1
# don't forget to update SCI and SCIVERSION in the buildlink3.mk file when
# SCIBASE is updated.
WRKSRC=		${WRKDIR}/${SCIBASE}

BROKEN_ON_PLATFORM+=	${LP64PLATFORMS}

USE_LANGUAGES=		c fortran77
USE_X11BASE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		tee

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-local-xaw
CONFIGURE_ARGS+=	--without-java

EVAL_PREFIX+=		TCL_PREFIX=tcl
EVAL_PREFIX+=		TK_PREFIX=tk
CONFIGURE_ARGS+=	--with-tcl-library=${TCL_PREFIX}/lib
CONFIGURE_ARGS+=	--with-tcl-include=${TCL_PREFIX}/include
CONFIGURE_ARGS+=	--with-tk-library=${TK_PREFIX}/lib
CONFIGURE_ARGS+=	--with-tk-include=${TK_PREFIX}/include
CONFIGURE_ENV+=		TCL_CONFIG_SH=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ENV+=		TK_CONFIG_SH=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh
CONFIGURE_ENV+=		CC_LDFLAGS=${X11_LDFLAGS:Q}\ ${COMPILER_RPATH_FLAG:Q}${BUILDLINK_PREFIX.tk:Q}/lib
CONFIGURE_ENV+=		FC_LDFLAGS=${X11_LDFLAGS:Q}\ ${COMPILER_RPATH_FLAG:Q}${BUILDLINK_PREFIX.tk:Q}/lib

# override HOME to avoid picking up a bad ${HOME}/.scilab during the build
MAKE_ENV+=		HOME=${WRKSRC:Q}
MAKE_ENV+=		PVM_ROOT=${PVM_ROOT:Q}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE:Q}

# FIXME -- this ugly hack will go away on newer versions of scilab where the build
# system has been improved significantly see:
#
#   scilab-4.1/routines/os_specific/getarg.c
#
.include "../../mk/compiler.mk"
.  if !empty(FC:Mgfortran) || (defined(PKGSRC_FORTRAN) && !empty(PKGSRC_FORTRAN:Mg95))
CFLAGS+=		-DG95_FORTRAN=1
.endif

PVM_ROOT?=		${LOCALBASE}/pvm3
CONFIGURE_ENV+=		PVM_ROOT=${PVM_ROOT:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
PLIST_SUBST+=		SCIBASE=${SCIBASE:Q}

UNWRAP_FILES+=		Makemex config/configuration config/Makeso.incl

BUILDLINK_DEPMETHOD.sablotron=	build

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "alpha")
pre-fetch: ${WRKDIR}
	@${ECHO} "===> Checking if you have working FPC"
	${CC} ${CFLAGS} -o ${WRKDIR}/chk_ieee ${FILESDIR}/chk_ieee.c
	@cd ${WRKDIR} && if ./chk_ieee ; then ${ECHO} "yes" ; else \
		${ECHO} "no" ; \
		${ECHO} "${PKGNAME} requires floating point completion on this system" ;\
		${ECHO} "Possible causes for this check failing are:" ;\
		${ECHO} "   - you have an old /usr/lib/* which was not compiled with -mieee" ;\
		${ECHO} "   - you have overridden CFLAGS for pkgsrc removing the -mieee flag" ;\
		${ECHO} "Without fixing this problem ${PKGNAME} will not work." ; ${FALSE} ; fi
.endif

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
#post-extract:
#.for f in scicos scicos_blocks
#	@extract_file=${DISTDIR}/${DIST_SUBDIR}/${f}.tar.gz ; export extract_file ; \
#		cd ${WRKSRC}/macros/${f} && ${EXTRACT_CMD}
#.endfor

# Scilab has runtime support for building shared objects that can be
# loaded.  It needs to know the right 'make' program.
post-patch:
	${MV} ${WRKSRC}/macros/util/ilib_compile.sci ${WRKSRC}/macros/util/ilib_compile.sci.bak
	${SED} 's|make -f|export PATH ; ${MAKE_PROGRAM} -f|g' \
		${WRKSRC}/macros/util/ilib_compile.sci.bak > \
		${WRKSRC}/macros/util/ilib_compile.sci
	${RM} ${WRKSRC}/macros/util/ilib_compile.sci.bak


# clean up any possible leftovers from 'make test' so that our PLIST
# will still be right.  Also clean up a reference to WRKSRC.
pre-install:
	cd ${WRKSRC}/examples && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} distclean
	${FIND} ${WRKSRC}/examples -name \*.blsav -print | ${XARGS} ${RM} -f
	${MV} ${WRKSRC}/maple/maple2scilab.mpl ${WRKSRC}/maple/maple2scilab.mpl.bak
	${SED} 's;${WRKSRC};${PREFIX}/lib/${SCIBASE};g' ${WRKSRC}/maple/maple2scilab.mpl.bak > \
		${WRKSRC}/maple/maple2scilab.mpl
	${RM} -f ${WRKSRC}/maple/maple2scilab.mpl.bak

# delete some .orig files that got created by patching
# also fix the libtool link
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/bin/scilink.orig
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/config/Makeso.incl.in.orig
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/macros/util/scipad.sci.orig
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/util/scidem.orig
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/util/scidoc.orig
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/libtool
	${LN} -s ${LOCALBASE}/bin/libtool ${DESTDIR}${PREFIX}/lib/${SCIBASE}/libtool
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/bin/dold
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/config/*.subst.sav
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/config/config.guess
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/config/config.sub

.for __tmp__ in scilab.g scilab.g.in scilab-gtk.g scilab-gtk.g.in
	${RM} -f ${DESTDIR}${PREFIX}/lib/${SCIBASE}/scripts/${__tmp__}
.endfor

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

# the "SCI=0 && unset SCI" is done because some of the tests really will
# fail if SCI is set to anything.
MAKE_ENV+=	SCI=${WRKSRC:Q}
do-test:
	cd ${WRKSRC}/examples && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		${TEE} ${WRKDIR}/examples.log

# scilab wants ocamlopt so use the same list here as in the
# lang/ocaml package
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.include "../../lang/ocaml/buildlink3.mk"
.else
PLIST_SRC=	${PKGDIR}/PLIST
CONFIGURE_ARGS+=	--without-ocaml
.endif
.include "../../parallel/pvm3/buildlink3.mk"
.include "../../textproc/sablotron/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
