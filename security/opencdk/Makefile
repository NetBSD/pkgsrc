# $NetBSD: Makefile,v 1.37 2014/01/01 11:52:02 wiz Exp $

DISTNAME=	opencdk-0.6.6
PKGREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/attic/opencdk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Open Crypto Development Kit
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

NOT_FOR_COMPILER=	xlc

REPLACE_PERL=		doc/gdoc

EGDIR=		${PREFIX}/share/examples/opencdk
HTMLDIR=	${PREFIX}/share/doc/html/opencdk

PKGCONFIG_OVERRIDE=	src/opencdk.pc.in

INSTALLATION_DIRS=	${HTMLDIR} ${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LIBS+=	-lnsl
.endif

pre-install:
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.gpg *.c ${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.2.2
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
