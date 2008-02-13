# $NetBSD: Makefile,v 1.71 2008/02/13 10:20:56 rillig Exp $

DISTNAME=	mc-4.6.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/utils/file/managers/mc/ \
		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/}

MAINTAINER=	pavel.arnost@clnet.cz
HOMEPAGE=	http://www.ibiblio.org/mc/
COMMENT=	User-friendly file manager and visual shell

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config unzip:run zip:run
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC+=		${PKGDIR}/PLIST.cons.saver
.endif

# remove dir if no extensions were installed there
post-install:
	rmdir ${DESTDIR}${PREFIX:Q}/lib/mc 2>/dev/null || ${TRUE}

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS+=	--without-ext2undel
CONFIGURE_ARGS+=	--without-gpm-mouse

CONFIGURE_ARGS+=	UNZIP=${TOOLS_PATH.unzip} ZIP=${TOOLS_PATH.zip}

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST.end

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
