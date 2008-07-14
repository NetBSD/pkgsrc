# $NetBSD: Makefile,v 1.3 2008/07/14 12:56:12 joerg Exp $
#

DISTNAME=	htop-0.6.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htop.sourceforge.net/
COMMENT=	Enhanced version of top utility

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
