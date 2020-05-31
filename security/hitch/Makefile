# $NetBSD: Makefile,v 1.16 2020/05/31 16:26:36 tnn Exp $

DISTNAME=	hitch-1.5.2
CATEGORIES=	security
MASTER_SITES=	https://hitch-tls.org/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hitch-tls.org/
COMMENT=	High performance SSL/TLS proxy
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

CHECK_PORTABILITY_SKIP+=	src/tests/*

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LIBS.SunOS+=		-lnsl -lsocket

BUILD_DEFS+=		HITCH_USER HITCH_GROUP HITCH_CERTS

HITCH_USER?=		hitch
HITCH_GROUP?=		hitch
HITCH_CERTS?=		${PKG_SYSCONFDIR}/certs.pem
HITCH_OCSP?=		${VARBASE}/db/hitch

PKG_GROUPS+=		${HITCH_GROUP}
PKG_USERS+=		${HITCH_USER}:${HITCH_GROUP}
PKG_GECOS.${HITCH_USER}= hitch daemon user

RCD_SCRIPTS=		hitch

MESSAGE_SUBST+=		HITCH_CERTS=${HITCH_CERTS}

SUBST_CLASSES+=		dir
SUBST_STAGE.dir=	pre-configure
SUBST_FILES.dir=	hitch.conf.example src/configuration.c
SUBST_VARS.dir=		HITCH_USER HITCH_GROUP HITCH_CERTS HITCH_OCSP
SUBST_MESSAGE.dir=	Setting default configuration values

PKG_SYSCONFSUBDIR=	hitch
CONF_FILES+=		share/examples/hitch/hitch.conf.example \
			${PKG_SYSCONFDIR}/hitch.conf

INSTALLATION_DIRS+=	share/examples/hitch

OWN_DIRS_PERMS+=	${HITCH_OCSP} ${HITCH_USER} ${HITCH_GROUP} 0755

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/doc/hitch/hitch.conf.example \
		${DESTDIR}${PREFIX}/share/examples/hitch

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/pyversion.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
