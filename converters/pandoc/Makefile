# $NetBSD: Makefile,v 1.17 2024/05/05 09:45:59 pho Exp $

.include "../../converters/hs-pandoc/version.mk"

DISTNAME=	# empty
PKGNAME=	pandoc-${PANDOC_VERSION}
CATEGORIES=	converters meta-pkgs
DISTFILES=	# empty

MAINTAINER=	zecrazytux@zecrazytux.net
COMMENT=	Conversion between documentation formats
LICENSE=	gnu-gpl-v2

META_PACKAGE=	yes

DEPENDS+=	pandoc-cli>=${PANDOC_VERSION}:../../converters/pandoc-cli

.include "../../mk/bsd.pkg.mk"
