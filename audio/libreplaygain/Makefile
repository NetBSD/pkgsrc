# $NetBSD: Makefile,v 1.1 2014/04/18 12:41:09 wiz Exp $

DISTNAME=		libreplaygain_r475
PKGNAME=		libreplaygain-0rc475
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.musepack.net/
COMMENT=		ReplayGain library for the musepack decoder
LICENSE=		gnu-lgpl-v2.1

USE_CMAKE=		yes
INSTALLATION_DIRS=	include/replaygain

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/replaygain/* ${DESTDIR}${PREFIX}/include/replaygain

.include "../../mk/bsd.pkg.mk"
