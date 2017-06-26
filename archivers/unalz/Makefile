# $NetBSD: Makefile,v 1.19 2017/06/26 09:48:34 adam Exp $

DISTNAME=		unalz-0.65
CATEGORIES=		archivers
MASTER_SITES=		https://kippler.com/win/unalz/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://kippler.com/win/unalz/
COMMENT=		Alzip archive (.alz) extractor
LICENSE=		zlib

BUILD_TARGET=		posix-utf8
USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/unalz

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${DESTDIR}${PREFIX}/bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
