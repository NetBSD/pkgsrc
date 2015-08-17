# $NetBSD: Makefile,v 1.9 2015/08/17 17:11:29 wiz Exp $
#

DISTNAME=	htop-1.0.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htop.sourceforge.net/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

USE_LIBTOOL=	yes

ONLY_FOR_PLATFORM=     Linux-*-* FreeBSD-*-* NetBSD-*-*

CONFIGURE_ENV+=		ac_cv_file__proc_stat=yes ac_cv_file__proc_meminfo=yes

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
