# $NetBSD: Makefile,v 1.14 2009/03/06 09:38:32 wiz Exp $

DISTNAME=	libtecla-1.6.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.astro.caltech.edu/~mcs/tecla/

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://www.astro.caltech.edu/~mcs/tecla/
COMMENT=	Interactive command line editing facilities

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/${PKGBASE}
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=		default

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

# reentrant causes compilation problems
.if ${OPSYS} != "SunOS"
CONFIGURE_ENV+=		tecla_cv_reentrant=no
.endif

.include "../../mk/bsd.pkg.mk"
