# $NetBSD: Makefile,v 1.3 2023/07/12 21:17:16 nia Exp $

DISTNAME=	monocypher-3.1.1
PKGREVISION=	1
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

.include "../../mk/bsd.pkg.mk"
