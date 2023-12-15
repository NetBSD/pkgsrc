# $NetBSD: Makefile,v 1.19 2023/12/15 13:49:37 wiz Exp $

DISTNAME=	libtecla-1.6.1
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.astro.caltech.edu/~mcs/tecla/
COMMENT=	Interactive command line editing facilities

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGBASE}
GNU_CONFIGURE=		yes
BUILD_TARGET=		default

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

# reentrant causes compilation problems
.if ${OPSYS} != "SunOS"
CONFIGURE_ENV+=		tecla_cv_reentrant=no
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
