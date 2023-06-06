# $NetBSD: Makefile,v 1.10 2023/06/06 12:42:09 riastradh Exp $

DISTNAME=	sniproxy-0.6.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=dlundquist/}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/dlundquist/sniproxy/
COMMENT=	Proxy that routes based on TLS server name extension
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_TOOLS+=	autoconf aclocal automake pkg-config
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/sniproxy.conf ${PKG_SYSCONFDIR}/sniproxy.conf

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

pre-configure:
	cd ${WRKSRC} && autoreconf --install && automake --add-missing --copy

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sniproxy.conf ${DESTDIR}${EGDIR}

.include "../../devel/libev/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../net/udns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
