# $NetBSD: Makefile,v 1.2 2019/05/06 09:17:12 sjmulder Exp $

DISTNAME=	bcal-2.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=jarun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jarun/bcal/
COMMENT=	Storage and general-purpose calculator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

DEPENDS+=	bc-[0-9]*:../../math/bc

MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
