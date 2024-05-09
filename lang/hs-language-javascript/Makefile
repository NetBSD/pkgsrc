# $NetBSD: Makefile,v 1.6 2024/05/09 01:32:23 pho Exp $

DISTNAME=	language-javascript-0.7.1.0
PKGREVISION=	5
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parser for JavaScript
LICENSE=	modified-bsd

USE_TOOLS+=	alex happy

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Kludge: happy has a problem reading
# ${WRKSRC}/src/Language/JavaScript/Parser/Grammer7.y in a locale other
# than this. We need to make this override the C locale that pkgsrc tries
# hard to ensure everything gets built in for the sake of reproducibility,
# so it has to come _after_ bsd.pkg.mk. The right locale would be C.UTF-8,
# but it was only recently introduced into NetBSD, so let's pick a locale
# that is pretty universally supported even if not exactly appropriate for
# this.
MAKE_ENV+=	LC_ALL=en_US.UTF-8
