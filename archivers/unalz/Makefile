# $NetBSD: Makefile,v 1.2 2005/03/02 16:18:47 minskim Exp $
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
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
