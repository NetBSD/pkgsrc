# $NetBSD: Makefile,v 1.20 2001/04/30 04:16:10 jlam Exp $

DISTNAME=	glx-20000813
PKGNAME=	Mesa-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	http://snow.ashlu.bc.ca/glx/snapshots/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		MesaLib-${MESA_VERSION}${EXTRACT_SUFX} \
		MesaDemos-${MESA_VERSION}${EXTRACT_SUFX}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://utah-glx.sourceforge.net/
COMMENT=	OpenGL like graphics library with GLX hardware acceleration

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5
BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=	tcl-8.3.2nb1:../../lang/tcl

BROKEN=		Package is outdated and has security problems.

CONFLICTS+=		Mesa-*
CONFLICTS+=		MesaLib-*
CONFLICTS+=		glu-*
CONFLICTS+=		glut-*
ONLY_FOR_PLATFORM=	NetBSD-*-i386

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes
CHECK_MESA=		yes
CONFIGURE_ARGS+=	--enable-static --with-mesa=${MESA_WRKSRC}
CONFIGURE_ARGS+=	--with-moduledir=${PREFIX}/lib/modules
CONFIGURE_ENV+=		TCLSH=${TCLSH}

.include "../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_MESA} != "NO"
IGNORE=			"Mesa-glx has already been installed as part of XFree86-4.x"
.endif

AUTOCONF=	${LOCALBASE}/bin/autoconf
WRKSRCDIRS=	${MESA_WRKSRC} ${WRKSRC} ${WRKSRC}/docs
MAKE_ENV+=	PERL=${PERL5}
MESA_VERSION=	3.1
MESA_WRKSRC=	${WRKDIR}/Mesa-${MESA_VERSION}
TCLSH=		${LOCALBASE}/bin/tclsh

pre-configure:
	@cd ${WRKSRC} && ${AUTOCONF} && cd docs && ${AUTOCONF}

do-configure:
	@for DIR in ${WRKSRCDIRS}; do \
	  cd $$DIR && \
	  ${SETENV} CC="${CC}" ac_cv_path_CC="${CC}" \
	    CFLAGS="${CFLAGS}" \
	    INSTALL="`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'` -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_DATA="${INSTALL_DATA}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	    ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

do-build:
	@for DIR in ${WRKSRCDIRS}; do \
	  cd $$DIR && \
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} \
	    ${ALL_TARGET}; \
	done

do-install:
	@for DIR in ${WRKSRCDIRS}; do \
	  cd $$DIR && \
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} \
	    ${INSTALL_TARGET}; \
	done
	${INSTALL_DATA} ${WRKSRC}/glx.conf ${PREFIX}/etc/glx.conf.default

.include "../../mk/bsd.pkg.mk"
