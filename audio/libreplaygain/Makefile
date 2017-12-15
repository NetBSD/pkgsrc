# $NetBSD: Makefile,v 1.2 2017/12/15 16:00:19 jperkin Exp $

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

SUBST_CLASSES+=		crlf
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	CMakeLists.txt
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/replaygain/* ${DESTDIR}${PREFIX}/include/replaygain

.include "../../mk/bsd.pkg.mk"
