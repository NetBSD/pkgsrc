# $NetBSD: Makefile,v 1.15 2013/10/30 06:49:54 dholland Exp $

.include "../../inputmethod/sj3/Makefile.common"

PKGNAME=	${DISTNAME:S/sj3-/sj3-server-/}
PKGREVISION=	3

COMMENT=	SJ3 Japanese input method server

CONFLICTS=	sj3-dict-[0-9]* sj3-server-bin-[0-9]*

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-external-lua
CONFIGURE_ARGS+=	--enable-server
CONFIGURE_ARGS+=	--enable-dict

CONF_FILES+=		share/examples/sj3/sj3proxy.lua.example \
			${PKG_SYSCONFDIR}/sj3proxy.lua
CONF_FILES+=		share/examples/sj3/sj3serv.lua.example \
			${PKG_SYSCONFDIR}/sj3serv.lua

OWN_DIRS_PERMS+=	${VARBASE}/sj3/run ${SJ3OWNER} ${SJ3GROUP} 755
OWN_DIRS_PERMS+=	${VARBASE}/sj3/dict/user ${SJ3OWNER} ${SJ3GROUP} 700
CONF_FILES_PERMS+=	libdata/sj3main.dic \
			${VARBASE}/sj3/dict/sj3main.dic \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 644

RCD_SCRIPTS=		sj3proxy sj3serv

INSTALLATION_DIRS+=	libdata

post-install:
	${INSTALL_DATA} ${WRKSRC}/dict/sj3main.dic \
		${DESTDIR}${PREFIX}/libdata/sj3main.dic

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
