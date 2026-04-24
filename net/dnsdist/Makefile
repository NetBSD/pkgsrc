# $NetBSD: Makefile,v 1.48 2026/04/24 17:11:17 wiz Exp $

DISTNAME=	dnsdist-2.0.5
CATEGORIES=	net
MASTER_SITES=	https://downloads.powerdns.com/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://dnsdist.org/
COMMENT=	Highly DNS-, DoS- and abuse-aware loadbalancer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=			DNSDIST_USER DNSDIST_GROUP
DNSDIST_USER?=			dnsdist
DNSDIST_GROUP?=			dnsdist
PKG_GROUPS+=			${DNSDIST_GROUP}
PKG_USERS+=			${DNSDIST_USER}:${DNSDIST_GROUP}
PKG_GECOS.${DNSDIST_USER}=	dnsdist daemon user

CHECK_WRKREF_SKIP+=		bin/dnsdist

FILES_SUBST+=	DNSDIST_USER=${DNSDIST_USER}
FILES_SUBST+=	DNSDIST_GROUP=${DNSDIST_GROUP}

CONFIGURE_ARGS+=	--enable-dns-over-tls
CONFIGURE_ARGS+=	--enable-dnscrypt
CONFIGURE_ARGS+=	--enable-dnstap
CONFIGURE_ARGS+=	--with-libsodium
CONFIGURE_ARGS+=	--with-libssl
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ARGS+=	--with-nghttp2
CONFIGURE_ARGS+=	--with-re2
CONFIGURE_ARGS+=	--without-net-snmp
CONFIGURE_ARGS+=	--enable-dns-over-https
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-boost=${BUILDLINK_PREFIX.boost-headers}

.include "../../mk/readline.buildlink3.mk"

.if ${READLINE_TYPE} == "editline"
CONFIGURE_ARGS+=	--with-libedit
CONFIGURE_ENV+=		LIBEDIT_CFLAGS="-I${BUILDLINK_PREFIX.editlinereadline}/include"
CONFIGURE_ENV+=		LIBEDIT_LIBS="-L${BUILDLINK_PREFIX.editlinereadline}/lib ${BUILDLINK_LDADD.editlinereadline}"
.else
CONFIGURE_ARGS+=	--without-libedit
.endif

EGDIR=			${PREFIX}/share/examples/dnsdist
CONF_FILES=		${EGDIR}/dnsdist.conf-dist ${PKG_SYSCONFDIR}/dnsdist.conf
INSTALLATION_DIRS+=	${EGDIR}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

RCD_SCRIPTS+=		dnsdist

.include "../../databases/lmdb/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../net/fstrm/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
