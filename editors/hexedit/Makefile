# $NetBSD: Makefile,v 1.28 2008/11/06 19:06:32 snj Exp $

DISTNAME=	hexedit-1.2.12
CATEGORIES=	editors
MASTER_SITES=	http://rigaux.org/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://merd.sourceforge.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=			${WRKDIR}/hexedit
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
