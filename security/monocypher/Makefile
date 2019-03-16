# $NetBSD: Makefile,v 1.1 2019/03/16 09:17:09 maya Exp $

DISTNAME=	monocypher-2.0.5
CATEGORIES=	security
MASTER_SITES=	https://monocypher.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monocypher.org/
COMMENT=	Easy to use, deploy and auditable crypto library
LICENSE=	cc0-1.0-universal OR 2-clause-bsd

USE_TOOLS+=	gmake
MAKE_FILE=	makefile
MAKE_ENV+=	MAN_DIR=${DESTDIR}/${PKGMANDIR}
TEST_TARGET=	test

# We default to binaries portable to more than one arch.
BUILDLINK_TRANSFORM+=	rm:-march=native

.include "../../mk/bsd.pkg.mk"
