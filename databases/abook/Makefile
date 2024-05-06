# $NetBSD: Makefile,v 1.34 2024/05/06 08:33:49 jperkin Exp $
#

DISTNAME=	abook-0.6.1
CATEGORIES=	databases
MASTER_SITES=	http://abook.sourceforge.net/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://abook.sourceforge.net/
COMMENT=	Text-based addressbook program
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

USE_FEATURES+=		strnlen

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
