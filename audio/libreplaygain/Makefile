# $NetBSD: Makefile,v 1.3 2020/01/26 17:30:43 rillig Exp $

DISTNAME=		libreplaygain_r475
PKGNAME=		libreplaygain-0rc475
CATEGORIES=		audio
MASTER_SITES=		http://files.musepack.net/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.musepack.net/
COMMENT=		ReplayGain library for the musepack decoder
LICENSE=		gnu-lgpl-v2.1

USE_CMAKE=		yes
INSTALLATION_DIRS=	include/replaygain

SUBST_CLASSES+=		crlf
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	CMakeLists.txt
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/replaygain/* ${DESTDIR}${PREFIX}/include/replaygain

.include "../../mk/bsd.pkg.mk"
