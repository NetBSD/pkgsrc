# $NetBSD: Makefile,v 1.8 2000/10/01 03:25:03 kim Exp $
#

DISTNAME=	irrd-1.5-beta-Sept-24-1999
PKGNAME=	irrd-1.5-beta-19990924
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radb/irrd/source/ \
		ftp://ftp.merit.edu/radb/irrd/source/old_releases/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.irrd.net/

BUILD_DEPENDS+=	autoreconf:../../devel/autoconf
BUILD_DEPENDS+=	bison:../../devel/bison

WRKSRC=		${WRKDIR}/irrd-1.5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gdbm --with-db1
CONFIGURE_ARGS+= --disable-thread
CONFIGURE_ENV+=	YACC=bison

pre-configure:
	@(cd ${WRKSRC} && autoreconf)

.include "../../mk/bsd.prefs.mk"

.if defined(IRRD_USE_PGP) && ${IRRD_USE_PGP} == 5
DEPENDS+=	pgp-5.*:../../security/pgp5
.elif defined(IRRD_USE_PGP) && ${IRRD_USE_PGP} == 2
DEPENDS+=	pgp-2.*:../../security/pgp2
.else
CONFIGURE_ARGS+= --without-pgp
.endif

.if defined(USE_INET6) && ${USE_INET6} == "YES"
# default
# CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
