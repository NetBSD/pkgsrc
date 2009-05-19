# $NetBSD: Makefile,v 1.26 2009/05/19 08:59:01 wiz Exp $

DISTNAME=		xmill-0.9.1
PKGREVISION=		3
CATEGORIES=		archivers
MASTER_SITES=		http://www.cs.washington.edu/homes/suciu/XMILL/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Specialized compressor for XML
LICENSE=		xmill-license

RESTRICTED=		Redistribution not permitted
# It is not entirely clear that noncommercial redistribution is
# permitted, but it's too hard to read the license, so it's marked as
# non-redistributable to err on the side of caution.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
MAKE_FILE=		makefile
USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xmill
	${INSTALL_DATA} ${WRKSRC}/documentation/COPYRIGHT.txt \
		${WRKSRC}/documentation/LICENSE.txt \
		${WRKSRC}/documentation/MANUAL.txt \
		${WRKSRC}/documentation/README.txt \
		${WRKSRC}/documentation/xmill.ps.gz \
		${WRKSRC}/documentation/xmill-09-doc.txt \
		${DESTDIR}${PREFIX}/share/doc/xmill
	${INSTALL_PROGRAM} ${WRKSRC}/unix/xcmill \
		${WRKSRC}/unix/xdemill \
		${WRKSRC}/unix/xmillexample \
		${WRKSRC}/unix/xmillinspect \
		${WRKSRC}/unix/xmilltest \
		${DESTDIR}${PREFIX}/bin

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
