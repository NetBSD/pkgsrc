# $NetBSD: Makefile,v 1.11 2011/11/25 21:26:14 joerg Exp $
#

DISTNAME=	softhsm-1.3.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.opendnssec.org/files/source/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.opendnssec.org/softhsm/
COMMENT=	Cryptographic store accessible through a PKCS\#11 interface
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=    user-destdir

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

EGDIR=			${PREFIX}/share/examples/softhsm

SUBST_CLASSES+=         paths
SUBST_FILES.paths=      ${WRKSRC}/Makefile.in
SUBST_STAGE.paths=      post-patch
SUBST_SED.paths=        -e 's,@EGDIR@,${EGDIR},'

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

CONF_FILES=		${EGDIR}/softhsm.conf ${PKG_SYSCONFDIR}/softhsm.conf

INSTALLATION_DIRS=	${EGDIR} etc bin lib
OWN_DIRS=		${VARBASE}/softhsm

pre-install:
	${INSTALL_DATA} ${WRKSRC}/softhsm.conf ${DESTDIR}${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/botan/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
