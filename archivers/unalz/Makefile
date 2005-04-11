# $NetBSD: Makefile,v 1.3 2005/04/11 21:44:50 tv Exp $
#

DISTNAME=		unalz-0.31
CATEGORIES=		archivers
MASTER_SITES=		http://www.kipple.pe.kr/win/unalz/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pyrasis@chol.com
HOMEPAGE=		http://www.kipple.pe.kr/win/unalz/
COMMENT=		Open-source ALZ extractor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		posix
NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
