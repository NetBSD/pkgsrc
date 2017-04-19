# $NetBSD: Makefile,v 1.11 2017/04/19 13:39:38 wiz Exp $

DISTNAME=	mlr-5.1.0
PKGNAME=	${DISTNAME:S/mlr/miller/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnkerl/}
GITHUB_PROJECT=	miller
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/johnkerl/miller/
COMMENT=	Command-line CSV processor
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
