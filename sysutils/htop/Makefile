# $NetBSD: Makefile,v 1.19 2020/01/26 17:32:09 rillig Exp $

DISTNAME=	htop-2.2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://hisham.hm/htop/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hisham.hm/htop/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

REPLACE_PYTHON+=	scripts/MakeHeader.py
CONFIGURE_ENV+=		ac_cv_file__proc_meminfo=yes
CONFIGURE_ENV+=		ac_cv_file__proc_stat=yes

.include "../../lang/python/application.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
