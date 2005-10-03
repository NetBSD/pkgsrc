# $NetBSD: Makefile,v 1.7 2005/10/03 04:12:20 minskim Exp $
#

DISTNAME=		unalz-0.52
CATEGORIES=		archivers
MASTER_SITES=		http://www.kipple.pe.kr/win/unalz/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-wip-discuss@lists.kldp.net
HOMEPAGE=		http://www.kipple.pe.kr/win/unalz/
COMMENT=		Alzip archive (.alz) extractor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_TARGET=		posix-utf8
NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/unalz

INSTALLATION_DIRS=	bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
