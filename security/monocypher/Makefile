# $NetBSD: Makefile,v 1.2 2020/10/19 12:30:30 mef Exp $

DISTNAME=	monocypher-3.1.1
CATEGORIES=	security
MASTER_SITES=	https://monocypher.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monocypher.org/
COMMENT=	Easy to use, deploy and auditable crypto library
LICENSE=	cc0-1.0-universal OR 2-clause-bsd

USE_TOOLS+=	gmake
MAKE_FILE=	makefile
MAKE_ENV+=	MANDIR=${DESTDIR}/${PKGMANDIR}
TEST_TARGET=	test

# We default to binaries portable to more than one arch.
BUILDLINK_TRANSFORM+=	rm:-march=native

.include "../../mk/bsd.pkg.mk"
