# $NetBSD: Makefile,v 1.29 2010/01/29 19:45:03 joerg Exp $

DISTNAME=	hexedit-1.2.12
CATEGORIES=	editors
MASTER_SITES=	http://rigaux.org/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://merd.sourceforge.net/pixel/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/hexedit
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
