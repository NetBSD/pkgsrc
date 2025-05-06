# $NetBSD: Makefile,v 1.11 2025/05/06 15:49:16 schmonz Exp $

DISTNAME=		${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=		${GITHUB_PROJECT}-0.6.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=dlundquist/}
GITHUB_PROJECT=		sniproxy
GITHUB_TAG=		2d9965388712faa6ef74f7229f38e3a177904bae

MAINTAINER=		wiedi@frubar.net
HOMEPAGE=		https://github.com/dlundquist/sniproxy/
COMMENT=		Proxy HTTP and TLS based on hostname in request
LICENSE=		2-clause-bsd

USE_LANGUAGES=		c
USE_CC_FEATURES=	c99
USE_TOOLS+=		autoconf aclocal automake pkg-config
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-dns
USE_LIBTOOL=		YES

TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/sniproxy.conf ${PKG_SYSCONFDIR}/sniproxy.conf

CPPFLAGS.SunOS+=	-D__EXTENSIONS__ -D_XOPEN_SOURCE=600
LDFLAGS.SunOS+=		-lsocket -lnsl

SUBST_CLASSES+=		pkgvars
SUBST_STAGE.pkgvars=	do-configure
SUBST_FILES.pkgvars=	src/sniproxy.c sniproxy.conf \
			man/sniproxy.8 man/sniproxy.conf.5
SUBST_VARS.pkgvars=	PKG_SYSCONFDIR VARBASE SNIPROXY_USER SNIPROXY_GROUP

PKG_USERS_VARS+=	SNIPROXY_USER
PKG_GROUPS_VARS+=	SNIPROXY_GROUP
PKG_GROUPS+=		${SNIPROXY_GROUP}
PKG_USERS+=		${SNIPROXY_USER}:${SNIPROXY_GROUP}

RCD_SCRIPTS=		sniproxy

BUILD_DEFS+=		VARBASE PKG_SYSCONFBASE

TEST_TARGET=		check
#USE_TOOLS+=		perl
#REPLACE_PERL+=		tests/*_test

pre-configure:
	cd ${WRKSRC} && autoreconf --install && automake --add-missing --copy

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sniproxy.conf ${DESTDIR}${EGDIR}

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../net/udns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
