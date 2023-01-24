# $NetBSD: Makefile,v 1.4 2023/01/24 18:36:20 wiz Exp $

DISTNAME=		libreplaygain_r475
PKGNAME=		libreplaygain-0rc475
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.musepack.net/
COMMENT=		ReplayGain library for the musepack decoder
LICENSE=		gnu-lgpl-v2.1

INSTALLATION_DIRS=	include/replaygain

SUBST_CLASSES+=		crlf
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	CMakeLists.txt
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/replaygain/* ${DESTDIR}${PREFIX}/include/replaygain

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
