# $NetBSD: Makefile,v 1.27 2007/11/25 11:46:59 wiz Exp $

DISTNAME=	hexedit-1.2.10
PKGREVISION=	1
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
