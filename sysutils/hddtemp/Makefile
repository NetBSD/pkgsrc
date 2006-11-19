# $NetBSD: Makefile,v 1.2 2006/11/19 09:44:35 wiz Exp $

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
ONLY_FOR_PLATFORM=      Linux-*-*

USE_LANGUAGES=		c
USE_PKGLOCALEDIR=	YES

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/misc
	${INSTALL_DATA} ${DISTDIR}/hddtemp.db ${PREFIX}/share/misc

.include "../../mk/bsd.pkg.mk"
