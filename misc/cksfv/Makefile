# $NetBSD: Makefile,v 1.29 2020/01/26 17:31:43 rillig Exp $
#

DISTNAME=	cksfv-1.3.14
CATEGORIES=	misc
MASTER_SITES=	http://zakalwe.fi/~shd/foss/cksfv/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zakalwe.fi/~shd/foss/cksfv/
COMMENT=	Check and create simple file verification (SFV) listings
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS=	share/doc/cksfv

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--package-prefix=${DESTDIR:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR}
CONFIGURE_ARGS+=	--compiler=${CC:Q}
TEST_TARGET=		check

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cksfv

.include "../../mk/bsd.pkg.mk"
