# $NetBSD: Makefile,v 1.4 2026/08/26 10:19:08 adam Exp $

DISTNAME=	knot-resolver-6.4.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-resolver/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://secure.nic.cz/files/knot-resolver/
COMMENT=	Knot (resolver) DNS server
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	cmake
USE_TOOLS+=	bash
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize

RCD_SCRIPTS=	kresd

BUILD_DEFS+=			KRESD_USER KRESD_GROUP VARBASE
KRESD_USER?=			kresd
KRESD_GROUP?=			kresd
PKG_GROUPS+=			${KRESD_GROUP}
PKG_USERS+=			${KRESD_USER}:${KRESD_GROUP}
PKG_GECOS.${KRESD_USER}=	kresd daemon user
PKG_GROUPS_VARS+=		KRESD_GROUP
PKG_USERS_VARS=			KRESD_USER


CONF_FILES+=	${PREFIX}/share/examples/knot-resolver/icann-ca.pem  ${PKG_SYSCONFDIR}/knot-resolver/icann-ca.pem
CONF_FILES+=	${PREFIX}/share/examples/knot-resolver/root.hints    ${PKG_SYSCONFDIR}/knot-resolver/root.hints
CONF_FILES+=	${PREFIX}/share/examples/knot-resolver/root.keys     ${PKG_SYSCONFDIR}/knot-resolver/root.keys

AUTO_MKDIRS=		yes

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/knot-resolver ${KRESD_USER} ${KRESD_GROUP} 0755

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/knot-resolver/icann-ca.pem ${DESTDIR}${PREFIX}/share/examples/knot-resolver/
	${MV} ${DESTDIR}${PREFIX}/etc/knot-resolver/root.hints ${DESTDIR}${PREFIX}/share/examples/knot-resolver/
	${MV} ${DESTDIR}${PREFIX}/etc/knot-resolver/root.keys ${DESTDIR}${PREFIX}/share/examples/knot-resolver/
	${RMDIR} ${DESTDIR}${PREFIX}/etc/knot-resolver

.include "../../net/knot/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../databases/lmdb/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
