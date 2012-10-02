# $NetBSD: Makefile,v 1.1 2012/10/02 22:40:07 pettai Exp $
#

DISTNAME=	knot-1.1.0
CATEGORIES=	net
MASTER_SITES=	http://public.nic.cz/files/knot-dns/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.knot-dns.cz/
COMMENT=	Knot (auth) DNS server
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=		VARBASE

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/knot
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

USE_LIBTOOL=	yes
USE_TOOLS+=	flex gmake

EGDIR=			${PREFIX}/share/examples/knot
KNOT_SYSCONFDIR=	${PKG_SYSCONFDIR}/knot

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/samples/Makefile.in
SUBST_STAGE.paths=	post-patch
SUBST_SED.paths=	-e 's,@EGDIR@,${EGDIR},'

CONF_FILES=	${EGDIR}/knot.sample.conf \
			${KNOT_SYSCONFDIR}/knot.sample.conf
CONF_FILES+=	${EGDIR}/example.com.zone \
			${KNOT_SYSCONFDIR}/example.com.zone

INSTALLATION_DIRS=	${EGDIR} ${KNOT_SYSCONFDIR}
OWN_DIRS+=		${VARBASE}/knot

.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
