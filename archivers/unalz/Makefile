# $NetBSD: Makefile,v 1.1.1.1 2004/12/03 17:17:10 minskim Exp $
#

DISTNAME=	unalz
PKGNAME=	unalz-0.20
CATEGORIES=	archivers
MASTER_SITES=	http://www.kipple.pe.kr/win/unalz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pyrasis@chol.com
HOMEPAGE=	http://www.kipple.pe.kr/win/unalz/
COMMENT=	Open-source ALZ extractor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/unalz
NO_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++

MAKEFILE=		makefile

INSTALLATION_DIRS=	bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unalz ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
