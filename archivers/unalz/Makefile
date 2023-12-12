# $NetBSD: Makefile,v 1.20 2023/12/12 12:18:07 zafer Exp $

DISTNAME=		unalz-0.65
CATEGORIES=		archivers
MASTER_SITES=		http://kippler.com/win/unalz/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kippler.com/win/unalz/
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
