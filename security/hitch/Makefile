# $NetBSD: Makefile,v 1.1 2016/05/25 20:15:35 fhajny Exp $

DISTNAME=	hitch-1.2.0
CATEGORIES=	security
MASTER_SITES=	https://hitch-tls.org/source/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://hitch-tls.org/
COMMENT=	High performance SSL/TLS proxy
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-rst2man=${PREFIX}/bin/rst2man.py${PYVERSSUFFIX}

CPPFLAGS.SunOS+=	-D__EXTENSIONS__
LIBS.SunOS+=		-lsocket

BUILD_DEFS+=		HITCH_USER HITCH_GROUP HITCH_CERTS

HITCH_USER?=		hitch
HITCH_GROUP?=		hitch
HITCH_CERTS?=		${PKG_SYSCONFDIR}/certs.pem

PKG_GROUPS+=		${HITCH_GROUP}
PKG_USERS+=		${HITCH_USER}:${HITCH_GROUP}
PKG_GECOS.${HITCH_USER}=hitch daemon user

RCD_SCRIPTS=		hitch

MESSAGE_SUBST+=		HITCH_CERTS=${HITCH_CERTS}

SUBST_CLASSES+=		dir
SUBST_STAGE.dir=	pre-configure
SUBST_FILES.dir=	hitch.conf.ex
SUBST_VARS.dir=		HITCH_USER HITCH_GROUP HITCH_CERTS
SUBST_MESSAGE.dir=	Setting default configuration values

PKG_SYSCONFSUBDIR=	hitch
CONF_FILES+=		share/examples/hitch/hitch.conf.ex \
			${PKG_SYSCONFDIR}/hitch.conf

INSTALLATION_DIRS+=	share/examples/hitch

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/doc/hitch/hitch.conf.ex \
		${DESTDIR}${PREFIX}/share/examples/hitch

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/pyversion.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
