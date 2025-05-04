# $NetBSD: Makefile,v 1.44 2025/05/04 13:17:38 nia Exp $

DISTNAME=	dropbear-2025.87
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://matt.ucc.asn.au/dropbear/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://matt.ucc.asn.au/dropbear/dropbear.html
COMMENT=	Small SSH2 server and client, aimed at embedded market
LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} --disable-bundled-libtom
USE_TOOLS+=		gmake

.include "../../x11/xauth/builtin.mk"

CPPFLAGS+=		-DXAUTH_COMMAND="\"${XAUTHBASE}/bin/xauth\""

CFLAGS.NetBSD+=		-DHAVE_NETINET_IN_SYSTM_H
LDFLAGS.SunOS+=		-lsocket -lnsl

BUILD_TARGET=		all scp

PKG_SYSCONFSUBDIR=	dropbear

RCD_SCRIPTS+=		dropbear

OWN_DIRS+=		${PKG_SYSCONFDIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	src/default_options.h
SUBST_VARS.paths=	PKG_SYSCONFDIR
SUBST_VARS.paths+=	PREFIX

SUBST_CLASSES+=		config
SUBST_MESSAGE.config=	Fixing path to config directory.
SUBST_STAGE.config=	post-build
SUBST_FILES.config=	manpages/dropbear.8 manpages/dropbearkey.1
SUBST_SED.config=	-e "s,/etc/dropbear/,${PKG_SYSCONFDIR:Q},g"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scp ${DESTDIR}${PREFIX}/bin/dbscp

.include "options.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.include "../../security/libtomcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
