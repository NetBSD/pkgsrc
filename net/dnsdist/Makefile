# $NetBSD: Makefile,v 1.25 2024/05/29 16:33:50 adam Exp $

DISTNAME=	dnsdist-1.8.0
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	https://downloads.powerdns.com/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnsdist.org/
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++11
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

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
CONFIGURE_ARGS+=	--enable-dnstap
CONFIGURE_ARGS+=	--with-libsodium
CONFIGURE_ARGS+=	--with-libssl
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ARGS+=	--with-nghttp2
CONFIGURE_ARGS+=	--with-re2
CONFIGURE_ARGS+=	--without-net-snmp

CONFIGURE_ENV+=		LIBEDIT_CFLAGS="-I${BUILDLINK_PREFIX.editlinereadline}/include"
CONFIGURE_ENV+=		LIBEDIT_LIBS="-L${BUILDLINK_PREFIX.editlinereadline}/lib ${BUILDLINK_LDADD.editlinereadline}"

RCD_SCRIPTS+=		dnsdist

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${MV} share/examples/dnsdist/dnsdist.conf-dist share/examples/dnsdist/dnsdist.conf || ${TRUE}

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
