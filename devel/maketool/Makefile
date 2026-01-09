# $NetBSD: Makefile,v 1.43 2026/01/09 07:37:51 wiz Exp $

DISTNAME=	maketool-0.7-src
PKGNAME=	maketool-0.7
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://www.aydogan.net/distfiles/devel/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://home.alphalink.com.au/~gnb/maketool/
COMMENT=	Graphical front end to GNU make

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
