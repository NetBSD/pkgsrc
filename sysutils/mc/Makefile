# $NetBSD: Makefile,v 1.92 2012/12/19 16:00:21 joerg Exp $

DISTNAME=	mc-4.7.0.10
PKGREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.midnight-commander.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://www.midnight-commander.org/
COMMENT=	User-friendly file manager and visual shell
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		pkg-config unzip:run
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

CHECK_INTERPRETER_SKIP=	libexec/mc/extfs.d/s3+

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

.if !empty(PKG_OPTIONS:Mmc-edit)
CONFFILES+=	syntax/Syntax
.endif

.if !empty(PKG_OPTIONS:Mmc-vfs)
CONFFILES+=	sfs.ini
.endif

.if !empty(PKG_OPTIONS:Mmc-charset)
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
