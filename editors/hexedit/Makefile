# $NetBSD: Makefile,v 1.37 2023/01/09 21:08:06 fcambus Exp $

DISTNAME=	hexedit-1.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=pixel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rigaux.org/hexedit.html
COMMENT=	To view and edit files in hexadecimal or ASCII
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	aclocal autoconf automake autoheader

GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
