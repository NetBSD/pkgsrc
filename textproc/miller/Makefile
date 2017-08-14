# $NetBSD: Makefile,v 1.14 2017/08/14 21:22:55 wiz Exp $

DISTNAME=	mlr-5.2.2
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
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
