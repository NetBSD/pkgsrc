# $NetBSD: Makefile,v 1.16 2004/10/03 00:13:04 tv Exp $

DISTNAME=		xmill-0.9.1
PKGREVISION=		2
CATEGORIES=		archivers
MASTER_SITES=		http://www.cs.washington.edu/homes/suciu/XMILL/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Specialized compressor for XML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=		make
MAKEFILE=		makefile
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/documentation/COPYRIGHT.txt \
		${WRKSRC}/documentation/LICENSE.txt \
		${WRKSRC}/documentation/MANUAL.txt \
		${WRKSRC}/documentation/README.txt \
		${WRKSRC}/documentation/xmill.ps.gz \
		${WRKSRC}/documentation/xmill-09-doc.txt \
		${PREFIX}/share/doc/xmill
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xcmill \
		${WRKSRC}/unix/xdemill \
		${WRKSRC}/unix/xmillexample \
		${WRKSRC}/unix/xmillinspect \
		${WRKSRC}/unix/xmilltest \
		${PREFIX}/bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
