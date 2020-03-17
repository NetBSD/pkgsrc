# $NetBSD: Makefile,v 1.17 2020/03/17 14:38:25 fcambus Exp $

DISTNAME=	mlr-5.7.0
PKGNAME=	${DISTNAME:S/mlr/miller/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_PROJECT=	miller
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	flex
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
