# $NetBSD: Makefile,v 1.23 2004/10/03 00:14:38 tv Exp $

DISTNAME=	hexedit-1.2.10
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://merd.net/pixel/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://merd.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=			${WRKDIR}/hexedit
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
