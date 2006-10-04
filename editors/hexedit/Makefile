# $NetBSD: Makefile,v 1.26 2006/10/04 21:37:39 wiz Exp $

DISTNAME=	hexedit-1.2.10
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://merd.sourceforge.net/pixel/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://merd.sourceforge.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=			${WRKDIR}/hexedit
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
