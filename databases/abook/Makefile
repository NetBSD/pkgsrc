# $NetBSD: Makefile,v 1.27 2014/10/09 14:06:04 wiz Exp $
#

DISTNAME=	abook-0.6.0pre2
PKGNAME=	abook-0.6.0rc2
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://abook.sourceforge.net/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
