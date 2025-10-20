# $NetBSD: Makefile,v 1.1 2025/10/20 19:09:17 vins Exp $

DISTNAME=	acme-client-1.3.5
CATEGORIES=	security
# repo at	https://git.wolfsden.cz/acme-client-portable
MASTER_SITES=	https://files.wolfsden.cz/releases/acme-client/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://wolfsden.cz/project/acme-client.html
COMMENT=	Client for issuing certificates from ACME-complaint servers
LICENSE=	isc AND gnu-gpl-v2

BUILD_DEFS+=	VARBASE

USE_TOOLS+=	pkg-config yacc sed

GNU_CONFIGURE=	yes

BUILDLINK_TRANSFORM+=		opt:-std=c99:-std=gnu99			# strdup()
BUILDLINK_TRANSFORM.NetBSD+=	opt:-D_GNU_SOURCE=1:-D_OPENBSD_SOURCE	# strtonum()

LIBS.SunOS+=		-lsocket	# getaddrinfo

EGDIR=			share/examples/${PKGBASE}
CONF_FILES+=		${PREFIX}/${EGDIR}/acme-client.conf \
			${PKG_SYSCONFDIR}/acme-client.conf

INSTALLATION_DIRS+=	${EGDIR}
MAKE_DIRS+=		${PKG_SYSCONFDIR}/acme ${VARBASE}/www/acme

CONFIGURE_ARGS+=	--enable-libtls

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	usr.sbin/acme-client/acme-client.1
SUBST_FILES.paths+=	usr.sbin/acme-client/acme-client.conf.5
SUBST_FILES.paths+=	acme-client.conf
SUBST_SED.paths+=	-e "s:/etc/acme:${PKG_SYSCONFDIR}/acme:g"
SUBST_SED.paths+=	-e "s:/etc/examples:${PREFIX}/${EGDIR}:g"
SUBST_VARS.paths+=	PKG_SYSCONFDIR SSLDIR

post-install:
	${INSTALL_DATA} ${WRKSRC}/acme-client.conf \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
