# $NetBSD: Makefile,v 1.66 2006/09/14 15:23:28 joerg Exp $

DISTNAME=	mc-4.6.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/utils/file/managers/mc/ \
		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/}

MAINTAINER=	pavel.arnost@clnet.cz
HOMEPAGE=	http://www.ibiblio.org/mc/
COMMENT=	User-friendly file manager and visual shell

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

# see options.mk for an explanation of these options
PKG_OPTIONS_VAR=	PKG_OPTIONS.mc
PKG_SUPPORTED_OPTIONS=	charset edit glib12 ncurses samba slang subshell vfs x11
PKG_SUGGESTED_OPTIONS=	charset edit                      slang subshell vfs

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC+=		${PKGDIR}/PLIST.cons.saver
.endif

# remove dir if no extensions were installed there
post-install:
	@${RMDIR} ${PREFIX:Q}/lib/mc 2>/dev/null || ${TRUE}

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS+=	--without-ext2undel
CONFIGURE_ARGS+=	--without-gpm-mouse

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST.end

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
