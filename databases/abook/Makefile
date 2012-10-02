# $NetBSD: Makefile,v 1.24 2012/10/02 21:25:15 asau Exp $
#

DISTNAME=	abook-0.6.0pre2
PKGNAME=	abook-0.6.0rc2
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://abook.sourceforge.net/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
USE_GNU_READLINE=	yes
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
