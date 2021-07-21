# $NetBSD: Makefile,v 1.3 2021/07/21 14:40:29 taca Exp $

DISTNAME=	congen-1.7
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://flaterco.com/files/xtide/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flaterco.com/
COMMENT=	Constants generator for tidal constituents
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS=	bash gmake gsed
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

REPLACE_RUBY=	scripts/*.rb

.include "../../databases/libtcd/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
