# $NetBSD: Makefile,v 1.17 2006/10/04 21:49:19 wiz Exp $
#

DISTNAME=	cksfv-1.3.9
CATEGORIES=	misc
MASTER_SITES=	http://zakalwe.fi/~shd/foss/cksfv/files/ \
		http://zakalwe.fi/~shd/foss/cksfv/files/devel/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://zakalwe.fi/~shd/foss/cksfv/
COMMENT=	Check and create simple file verification (SFV) listings

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/man
CONFIGURE_ARGS+=	--compiler=${CC:Q}
TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cksfv
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cksfv

.include "../../mk/bsd.pkg.mk"
