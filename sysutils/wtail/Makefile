# $NetBSD: Makefile,v 1.12 2009/10/29 21:58:38 tnn Exp $
#

DISTNAME=	wtail-0.2.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.teaser.fr/~amajorel/wtail/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.teaser.fr/~amajorel/wtail/
COMMENT=	Watch multiple files at once

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	SED=${SED:Q}

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
