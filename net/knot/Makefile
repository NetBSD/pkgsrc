# $NetBSD: Makefile,v 1.84 2024/05/29 16:33:56 adam Exp $

DISTNAME=	knot-3.3.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://www.knot-dns.cz/
COMMENT=	Knot (auth) DNS server
LICENSE=	gnu-gpl-v3

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/knot
CONFIGURE_ARGS+=	--with-rundir=${VARBASE}/run/knot
CONFIGURE_ARGS+=	--with-storage=${VARBASE}/knot/lib
CONFIGURE_ARGS+=	--with-urcu=${BUILDLINK_PREFIX.userspace-rcu}
CONFIGURE_ARGS+=	--with-libidn=${BUILDLINK_PREFIX.libidn}

CONFIGURE_ARGS.NetBSD+=	--enable-recvmmsg=no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" 
CFLAGS +=	-march=i586 
.endif 

USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake pkg-config

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

PKGCONFIG_OVERRIDE=	src/dnssec/libdnssec.pc.in
PKGCONFIG_OVERRIDE+=	src/knotd.pc.in
PKGCONFIG_OVERRIDE+=	src/libknot.pc.in
PKGCONFIG_OVERRIDE+=	src/zscanner/libzscanner.pc.in

RCD_SCRIPTS=	knot

EGDIR=			${PREFIX}/share/examples/knot
PKG_SYSCONFSUBDIR=	knot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/samples/Makefile.in
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	EGDIR

CONF_FILES=	${EGDIR}/knot.sample.conf \
			${PKG_SYSCONFDIR}/knot.conf
CONF_FILES+=	${EGDIR}/example.com.zone \
			${PKG_SYSCONFDIR}/example.com.zone

INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS+=		${VARBASE}/knot

.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
