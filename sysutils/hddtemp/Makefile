# $NetBSD: Makefile,v 1.5 2012/10/23 19:51:07 asau Exp $

DISTNAME=	hddtemp-0.3-beta15
PKGNAME=	hddtemp-0.3b15
CATEGORIES=	sysutils
MASTER_SITES=	http://www.guzu.net/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} hddtemp.db
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	http://www.guzu.net/linux/hddtemp.php
COMMENT=	Gather temperature stats for disk drives

SITES.hddtemp.db=	http://www.guzu.net/linux/

PKG_INSTALLATION_TYPES=	overwrite pkgviews
ONLY_FOR_PLATFORM=	Linux-*-*

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	YES

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+=	share/misc

post-install:
	${INSTALL_DATA} ${DISTDIR}/hddtemp.db ${DESTDIR}${PREFIX}/share/misc

.include "../../mk/bsd.pkg.mk"
