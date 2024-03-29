# $NetBSD: Makefile,v 1.51 2024/02/17 02:20:26 adam Exp $

DISTNAME=	dnsmasq-2.90
CATEGORIES=	net
MASTER_SITES=	https://thekelleys.org.uk/dnsmasq/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://thekelleys.org.uk/dnsmasq/doc.html
COMMENT=	Lightweight, easy to configure DNS forwarder
LICENSE=	gnu-gpl-v3

RCD_SCRIPTS=	dnsmasq
EGDIR=		${PREFIX}/share/examples/dnsmasq
CONF_FILES=	${EGDIR}/dnsmasq.conf.example ${PKG_SYSCONFDIR}/dnsmasq.conf

.include "../../mk/bsd.prefs.mk"

DNSMASQ_USER?=		dnsmasq
.if ${OPSYS} == "Interix"
DNSMASQ_GROUP?=		nogroup
.else
DNSMASQ_GROUP?=		dnsmasq
.endif

PKG_GROUPS=		${DNSMASQ_GROUP}
PKG_USERS=		${DNSMASQ_USER}:${DNSMASQ_GROUP}
PKG_GECOS.${DNSMASQ_USER}= DNS\ forwarder\ user

.include "options.mk"

CFLAGS.SunOS+=	-DNO_IPSET

# Override the defaults
AUTO_MKDIRS=		yes
CFLAGS+=		-DCONFFILE='"${PKG_SYSCONFDIR}/dnsmasq.conf"'
MAKE_FLAGS+=		COPTS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}
INSTALL_MAKE_FLAGS+=	PREFIX="${PREFIX}"
INSTALL_MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}"
INSTALL_MAKE_FLAGS+=	LOCALEDIR="${PREFIX}/${PKGLOCALEDIR}"

# Upstream wants to use nawk, but awk should work just fine here.
BUILD_MAKE_FLAGS+=	AWK="${AWK}"
INSTALL_MAKE_FLAGS+=	AWK="${AWK}"

post-install:
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${DESTDIR}${EGDIR}
.if !empty(PKG_OPTIONS:Mdbus)
	${INSTALL_DATA} ${WRKSRC}/dbus/dnsmasq.conf \
		${DESTDIR}${EGDIR}/dnsmasq-dbus.conf
.endif

.include "../../mk/bsd.pkg.mk"
