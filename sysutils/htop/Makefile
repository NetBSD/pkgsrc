# $NetBSD: Makefile,v 1.16 2017/11/24 02:06:13 maya Exp $

DISTNAME=	htop-2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://hisham.hm/htop/releases/${PKGVERSION_NOREV}/
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hisham.hm/htop/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake aclocal autoheader autoconf
GNU_CONFIGURE=	yes
USE_NCURSES=	yes # uses ncurses mouse definitions

USE_LIBTOOL=	yes

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; \
	autoconf; \
	automake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && exists(/system/lxproc)
ONLY_FOR_PLATFORM+=	SunOS-*-*
CONFIGURE_ARGS+=	--with-proc=/system/lxproc
.endif

REPLACE_PYTHON+=	scripts/MakeHeader.py
CONFIGURE_ENV+=		ac_cv_file__proc_stat=yes ac_cv_file__proc_meminfo=yes

.include "../../lang/python/application.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
