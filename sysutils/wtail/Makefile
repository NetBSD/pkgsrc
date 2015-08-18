# $NetBSD: Makefile,v 1.15 2015/08/18 07:31:18 wiz Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

MAKE_ENV+=	SED=${SED:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
