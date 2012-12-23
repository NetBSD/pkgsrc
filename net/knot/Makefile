# $NetBSD: Makefile,v 1.7 2012/12/23 23:38:08 pettai Exp $
#

DISTNAME=	knot-1.1.3
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/
FETCH_USING=	curl

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.knot-dns.cz/
COMMENT=	Knot (auth) DNS server
LICENSE=	gnu-gpl-v3

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/knot
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/knot

USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake
RCD_SCRIPTS=	knot

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
