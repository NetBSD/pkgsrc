# $NetBSD: Makefile,v 1.48 2005/02/12 01:02:50 rillig Exp $

DISTNAME=	mc-4.6.1-pre2b
PKGNAME=	mc-4.6.1rc2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://pavelsh.pp.ru/mc/
#MASTER_SITES=	http://www.ibiblio.org/pub/Linux/utils/file/managers/mc/ \
#		${MASTER_SITE_SUNSITE:=utils/file/managers/mc/}

MAINTAINER=	pavel.arnost@clnet.cz
HOMEPAGE=	http://www.ibiblio.org/mc/
COMMENT=	User-friendly file manager and visual shell

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES

.if ${OPSYS} == "Linux"
PLIST_SRC+=	${PKGDIR}/PLIST.cons.saver
.endif

# remove dir if no extensions were installed there
post-install:
	@${RMDIR} ${PREFIX}/lib/mc 2>/dev/null || ${TRUE}

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS+=	--without-ext2undel
CONFIGURE_ARGS+=	--without-gpm-mouse

MC_FEATURES=		edit charset largefile samba subshell vfs x11
MC_DISABLE_FEATURES=	x11 samba

MC_SCREEN_LIBRARY= slang

.for feature in ${MC_FEATURES}

__feature:=${feature}

.	if empty(MC_DISABLE_FEATURES:M${feature})

.		if ${__feature} == edit
CONFIGURE_ARGS+=	--with-edit
PLIST_SRC+=		${PKGDIR}/PLIST.mcedit
.		elif ${__feature} == charset
CONFIGURE_ARGS+=	--enable-charset
.include "../../converters/libiconv/buildlink3.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.charset
.		elif ${__feature} == largefile
CONFIGURE_ARGS+=	--enable-largefile
.		elif ${__feature} == samba
CONFIGURE_ARGS+=	--with-samba
.		elif ${__feature} == subshell
CONFIGURE_ARGS+=	--with-subshell
.		elif ${__feature} == vfs
CONFIGURE_ARGS+=	--with-vfs
PLIST_SRC+=		${PKGDIR}/PLIST.vfs
.		elif ${__feature} == x11
USE_X11=		YES
CONFIGURE_ARGS+=	--with-x
.		endif

.	else

.		if ${__feature} == edit
CONFIGURE_ARGS+=	--without-edit
.		elif ${__feature} == charset
CONFIGURE_ARGS+=	--disable-charset
.		elif ${__feature} == largefile
CONFIGURE_ARGS+=	--disable-largefile
.		elif ${__feature} == samba
CONFIGURE_ARGS+=	--without-samba
.		elif ${__feature} == subshell
CONFIGURE_ARGS+=	--without-subshell
.		elif ${__feature} == vfs
CONFIGURE_ARGS+=	--without-vfs
.		elif ${__feature} == x11
CONFIGURE_ARGS+=	--without-x
.		endif

.	endif

.endfor

PLIST_SRC+=  	${PKGDIR}/PLIST

.if ${MC_SCREEN_LIBRARY} == "slang"
CONFIGURE_ARGS+=	--with-screen=slang
.include "../../devel/libslang/buildlink3.mk"
.elif ${MC_SCREEN_LIBRARY} == "ncurses"
CONFIGURE_ARGS+=	--with-screen=ncurses
.include "../../devel/ncurses/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-screen=mcslang
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
