# $NetBSD: Makefile,v 1.22 2018/08/22 09:46:36 wiz Exp $

DISTNAME=	mc-4.6.1
PKGREVISION=	22
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/utils/file/managers/mc/
MASTER_SITES+=	${MASTER_SITE_SUNSITE:=utils/file/managers/mc/}

MAINTAINER=	pavel.arnost@clnet.cz
HOMEPAGE=	http://www.ibiblio.org/mc/
COMMENT=	User-friendly file manager and visual shell (old 4.6 branch)

USE_TOOLS+=		pkg-config unzip:run zip:run gmake
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

PKG_SYSCONFSUBDIR=	mc
SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	vfs/extfs.c vfs/sfs.c
SUBST_VARS.conf=	PKG_SYSCONFDIR

.if !empty(PKG_OPTIONS:Mmc-vfs)
EGDIR=			${PREFIX}/share/examples/mc
CONF_FILES+=		${EGDIR}/extfs.ini ${PKG_SYSCONFDIR}/extfs.ini
CONF_FILES+=		${EGDIR}/sfs.ini ${PKG_SYSCONFDIR}/sfs.ini
.endif

post-install:
# remove dir if no extensions were installed there
	rmdir ${DESTDIR}${PREFIX:Q}/lib/mc 2>/dev/null || ${TRUE}
.if !empty(PKG_OPTIONS:Mmc-vfs)
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs/extfs/extfs.ini ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vfs/extfs/sfs.ini ${DESTDIR}${EGDIR}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
