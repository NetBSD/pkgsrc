# $NetBSD: Makefile,v 1.78 2011/01/23 14:36:10 wiz Exp $

DISTNAME=	mc-4.7.0.10
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.midnight-commander.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	vle@gmx.net
HOMEPAGE=	http://www.midnight-commander.org/
COMMENT=	User-friendly file manager and visual shell
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config unzip:run
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
PLIST_SRC+=		${PKGDIR}/PLIST.cons.saver
.endif

# we need working e2fsprogs and gpm packages first
CONFIGURE_ARGS+=	--without-ext2undel
CONFIGURE_ARGS+=	--without-gpm-mouse
CONFIGURE_ARGS+=	UNZIP=${TOOLS_PATH.unzip} ZIP=${TOOLS_PATH.zip}

PLIST_SRC+=		${PKGDIR}/PLIST

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/mc

CONFFILES=	cedit.menu edit.indent.rc edit.spell.rc filehighlight.ini \
		mc.ext mc.keymap mc.keymap.default mc.keymap.emacs mc.lib \
		mc.menu mc.menu.sr

.if !empty(PKG_OPTIONS:Medit)
CONFFILES+=	syntax/Syntax
.endif

.if !empty(PKG_OPTIONS:Mvfs)
CONFFILES+=	sfs.ini
.endif

.if !empty(PKG_OPTIONS:Mcharset)
CONFFILES+=	mc.charsets
.endif

OWN_DIRS+=	${PKG_SYSCONFDIR}/mc ${PKG_SYSCONFDIR}/mc/syntax

.for i in ${CONFFILES}
CONF_FILES+=	${EGDIR}/${i} ${PKG_SYSCONFDIR}/mc/${i}
.endfor

INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/syntax

post-install:
# remove dir if no extensions were installed there
	rmdir ${DESTDIR}${PREFIX}/lib/mc 2>/dev/null || ${TRUE}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
