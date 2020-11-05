# $NetBSD: Makefile,v 1.6 2020/11/05 09:07:07 ryoon Exp $
#

VERSION=	2.5.0
PKGREVISION=	4
DISTNAME=	softhsm-${VERSION}
PKGNAME=	softhsm2-${VERSION}
CATEGORIES=	security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://www.opendnssec.org/softhsm/
COMMENT=	Cryptographic store accessible through a PKCS\#11 interface
LICENSE=	2-clause-bsd

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-botan=${PREFIX}
CONFIGURE_ARGS+=	--with-objectstore-backend-db
CONFIGURE_ARGS+=	--with-migrate
CONFIGURE_ARGS+=	--disable-gost

EGDIR=			${PREFIX}/share/examples/softhsm

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/src/lib/common/Makefile.in
SUBST_STAGE.paths=	pre-configure
SUBST_VARS.paths=	EGDIR

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE
# For debugging:
CXXFLAGS+=		-g
INSTALL_UNSTRIPPED=	YES

CONF_FILES=		${EGDIR}/softhsm2.conf ${PKG_SYSCONFDIR}/softhsm2.conf

INSTALLATION_DIRS=	${EGDIR} etc bin lib
OWN_DIRS=		${VARBASE}/softhsm

pre-install:
	${INSTALL_DATA} ${WRKSRC}/src/lib/common/softhsm2.conf ${DESTDIR}${EGDIR}

USE_BUILTIN.sqlite3=NO
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
