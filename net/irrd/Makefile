# $NetBSD: Makefile,v 1.3 2000/03/30 20:28:12 fredb Exp $
#

DISTNAME=	irrd-1.5-beta-Sept-24-1999
PKGNAME=	irrd-1.5-beta-19990924
CATEGORIES=	net
MASTER_SITES=	http://www.merit.edu/radb/irrd/source/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.irrd.net/

BUILD_DEPENDS=	autoreconf:../../devel/autoconf
BUILD_DEPENDS=	bison:../../devel/bison

.include "../../mk/bsd.prefs.mk"

.ifdef IRRD_USE_PGP
.if ${IRRD_USE_PGP} == 5
DEPENDS+=	pgp-5.*:../../security/pgp5
.elif ${IRRD_USE_PGP} == 2
DEPENDS+=	pgp-2.*:../../security/pgp2
#.else
# IRRd will be built with pgpv or pgp if found!
#CONFIGURE_ARGS+=--without-pgp
.endif
.endif

.ifndef USE_INET6
CONFIGURE_ARGS+=	--disable-ipv6
.endif

WRKSRC=		${WRKDIR}/irrd-1.5

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-db1

pre-configure:
	@(cd ${WRKSRC} && autoreconf)

.include "../../mk/bsd.pkg.mk"
