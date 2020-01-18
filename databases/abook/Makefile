# $NetBSD: Makefile,v 1.31 2020/01/18 23:30:17 rillig Exp $
#

DISTNAME=	abook-0.6.1
CATEGORIES=	databases
MASTER_SITES=	http://abook.sourceforge.net/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://abook.sourceforge.net/
COMMENT=	Text-based addressbook program
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
USE_NCURSES=		yes # mouse API
GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
