# $NetBSD: Makefile,v 1.17 2022/08/06 17:21:05 he Exp $

DISTNAME=	dnsdist-1.5.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	https://downloads.powerdns.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdist.org/
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pkg-config

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=			DNSDIST_USER DNSDIST_GROUP
DNSDIST_USER?=			dnsdist
DNSDIST_GROUP?=			dnsdist
PKG_GROUPS+=			${DNSDIST_GROUP}
PKG_USERS+=			${DNSDIST_USER}:${DNSDIST_GROUP}
PKG_GECOS.${DNSDIST_USER}=	dnsdist daemon user

FILES_SUBST+=	DNSDIST_USER=${DNSDIST_USER}
FILES_SUBST+=	DNSDIST_GROUP=${DNSDIST_GROUP}
CONF_FILES+=	share/examples/dnsdist/dnsdist.conf \
		${PKG_SYSCONFDIR}/dnsdist.conf

CONFIGURE_ARGS+=	--enable-dns-over-tls
CONFIGURE_ARGS+=	--enable-dnscrypt
CONFIGURE_ARGS+=	--enable-fstrm
CONFIGURE_ARGS+=	--with-libsodium
CONFIGURE_ARGS+=	--with-libssl
CONFIGURE_ARGS+=	--with-protobuf
CONFIGURE_ARGS+=	--with-re2
CONFIGURE_ARGS+=	--without-net-snmp
CONFIGURE_ENV+=		LIBEDIT_CFLAGS="-I${BUILDLINK_PREFIX.libedit}/include"
CONFIGURE_ENV+=		LIBEDIT_LIBS="-L${BUILDLINK_PREFIX.libedit}/lib -ledit"

INSTALLATION_DIRS+=	share/examples/dnsdist
RCD_SCRIPTS+=		dnsdist

post-install:
	${INSTALL_DATA} ${.CURDIR}/files/dnsdist.conf \
		${DESTDIR}${PREFIX}/share/examples/dnsdist

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
