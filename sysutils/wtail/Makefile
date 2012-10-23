# $NetBSD: Makefile,v 1.13 2012/10/23 19:51:35 asau Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

MAKE_ENV+=	SED=${SED:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
