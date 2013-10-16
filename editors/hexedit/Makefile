# $NetBSD: Makefile,v 1.32 2013/10/16 21:59:30 roy Exp $

DISTNAME=	hexedit-1.2.13
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://rigaux.org/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://merd.sourceforge.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=			${WRKDIR}/hexedit
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
