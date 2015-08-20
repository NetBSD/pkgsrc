# $NetBSD: Makefile,v 1.10 2015/08/20 13:38:25 jperkin Exp $
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && exists(/system/lxproc)
ONLY_FOR_PLATFORM+=	SunOS-*-*
CONFIGURE_ARGS+=	--with-proc=/system/lxproc
.endif

CONFIGURE_ENV+=		ac_cv_file__proc_stat=yes ac_cv_file__proc_meminfo=yes

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
