# $NetBSD: Makefile,v 1.7 2002/10/25 17:32:32 wiz Exp $
#

DISTNAME=	naim-0.11.4.9
CATEGORIES=	chat
MASTER_SITES=	http://www.acm.rpi.edu/~n/	

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://site.rpi-acm.org/info/naim/
COMMENT=	ncurses-based AIM/IRC client

GNU_CONFIGURE=	YES

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
# newpad, keyname, wattr_get, wattr_set, pnoutrefresh, use_default_colors
USE_NCURSES=		YES

.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
