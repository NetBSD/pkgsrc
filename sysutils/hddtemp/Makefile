# $NetBSD: Makefile,v 1.1 2006/10/19 21:00:18 christos Exp $

DISTNAME=	hddtemp-0.3-beta15
PKGNAME=	hddtemp-0.3b15
CATEGORIES=	sysutils
EXTRACT_SUFX=	tar.bz2
MASTER_SITES=	http://www.guzu.net/files/

SITES.hddtemp.db=	http://www.guzu.net/linux/
DISTFILES+=	hddtemp.db


MAINTAINER=	christos@NetBSD.org
HOMEPAGE=	http://www.guzu.net/linux/hddtemp.php
COMMENT=	Gather temperature stats for disk drives

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
