# $NetBSD: Makefile,v 1.4 2011/08/06 16:36:41 cheusov Exp $
#

DISTNAME=	htop-0.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htop.sourceforge.net/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

USE_TOOLS+=	autoreconf autoconf automake
USE_LIBTOOL=	yes

pre-configure:
	set -e; cd ${WRKSRC}; autoreconf --force --install

.include "../../devel/ncurses/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
