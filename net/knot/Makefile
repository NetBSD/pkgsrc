# $NetBSD: Makefile,v 1.104 2026/09/09 14:25:20 drixter Exp $

DISTNAME=	knot-3.6.0
CATEGORIES=	net
MASTER_SITES=	https://knot-dns.nic.cz/release/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.knot-dns.cz/
COMMENT=	CZ.NIC Knot (auth) DNS server
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/knot
CONFIGURE_ARGS+=	--with-rundir=${VARBASE}/run/knot
CONFIGURE_ARGS+=	--with-storage=${VARBASE}/knot/lib

CONFIGURE_ARGS.NetBSD+=	--enable-recvmmsg=no

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i586
.endif

CFLAGS.SunOS+=	-D_XPG4_2
CFLAGS.SunOS+=	-D__EXTENSIONS__

USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake pkg-config

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

PKGCONFIG_OVERRIDE+=	src/knotd.pc.in
PKGCONFIG_OVERRIDE+=	src/libknot.pc.in
PKGCONFIG_OVERRIDE+=	src/zscanner/libzscanner.pc.in

RCD_SCRIPTS=	knot

EGDIR=			${PREFIX}/share/examples/knot
PKG_SYSCONFSUBDIR=	knot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	samples/Makefile.in
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	EGDIR

CONF_FILES=	${EGDIR}/knot.sample.conf \
			${PKG_SYSCONFDIR}/knot.conf
CONF_FILES+=	${EGDIR}/example.com.zone \
			${PKG_SYSCONFDIR}/example.com.zone

CHECK_WRKREF_SKIP+=	bin/* lib/* sbin/*

INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS+=		${VARBASE}/knot

.include "../../databases/lmdb/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/libidn2/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
