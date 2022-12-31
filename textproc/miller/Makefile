# $NetBSD: Makefile,v 1.24 2022/12/31 19:09:50 fcambus Exp $

DISTNAME=	miller-5.10.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	flex
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
