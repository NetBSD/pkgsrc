# $NetBSD: Makefile,v 1.17 2018/11/05 12:19:23 jperkin Exp $

DISTNAME=	htop-2.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://hisham.hm/htop/releases/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hisham.hm/htop/
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
