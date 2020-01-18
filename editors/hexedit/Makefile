# $NetBSD: Makefile,v 1.34 2020/01/18 23:30:45 rillig Exp $

DISTNAME=	hexedit-1.2.13
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://rigaux.org/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://merd.sourceforge.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

WRKSRC=			${WRKDIR}/hexedit
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
