# $NetBSD: Makefile,v 1.12 2017/08/07 08:26:38 jlam Exp $

.include "../../inputmethod/ja-freewnn-lib/Makefile.common"

PKGNAME=	ja-FreeWnn-server-1.11alpha23
PKGREVISION=	1

COMMENT+=	(Japanese server)

CONFIGURE_ARGS+=	--disable-libraries
# Following two lines give equivalent to previous 1.10 version
CONFIGURE_ARGS+=	--disable-cWnn
CONFIGURE_ARGS+=	--disable-kWnn

CONFIGURE_ARGS+=	--with-wnn-libraries=${BUILDLINK_PREFIX.ja-FreeWnn-lib}/lib
CONFIGURE_ARGS+=	--with-libwnn=yes
CONFIGURE_ARGS+=	--disable-sub-bindir
# use sbin/ instead of bin/
CONFIGURE_ARGS+=	--disable-traditional-layout

INSTALL_TARGET=	install install.man

RCD_SCRIPTS=    ja_freewnn

BUILD_DEFS=	FREEWNN_USER FREEWNN_GROUP IMDICTDIR

FREEWNN_USER=	wnn
FREEWNN_GROUP=	jserver
PKG_GROUPS=	${FREEWNN_GROUP}
PKG_USERS=	${FREEWNN_USER}:${FREEWNN_GROUP}

# sbin/jserver needs to be setuid to ${FREEWNN_USER}.
SPECIAL_PERMS+=	sbin/jserver ${FREEWNN_USER} ${FREEWNN_GROUP} 4511

OWN_DIRS+=		${IMDICTDIR}/wnn/ja_JP
OWN_DIRS_PERMS+=	${IMDICTDIR}/wnn/ja_JP/usr ${FREEWNN_USER} ${FREEWNN_GROUP} ${PKGDIRMODE}

.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
