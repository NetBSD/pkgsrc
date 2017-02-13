# $NetBSD: Makefile,v 1.28 2017/02/13 00:11:35 maya Exp $
#

DISTNAME=	vifm-0.8.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vifm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vifm.info/
COMMENT=	Curses based file manager with vi like keybindings
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl

USE_CURSES=	resize_term wide
FAKE_NCURSES=	yes
REPLACE_PERL=	src/vifm-convert-dircolors

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
