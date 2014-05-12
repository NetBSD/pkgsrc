# $NetBSD: Makefile,v 1.18 2014/05/12 14:52:54 pettai Exp $

DISTNAME=	knot-1.4.5
CATEGORIES=	net
MASTER_SITES=	https://secure.nic.cz/files/knot-dns/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.knot-dns.cz/
COMMENT=	Knot (auth) DNS server
LICENSE=	gnu-gpl-v3

# If you're not able to download the distfile, try using
#FETCH_USING=   curl # in mk.conf or on the command-line

BUILD_DEFS+=	VARBASE

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
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
