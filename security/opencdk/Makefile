# $NetBSD: Makefile,v 1.24 2007/02/05 22:59:00 wiz Exp $

DISTNAME=	opencdk-0.5.13
CATEGORIES=	security devel
MASTER_SITES=	http://josefsson.org/gnutls/releases/opencdk/ \
		ftp://ftp.gnutls.org/pub/gnutls/opencdk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Open Crypto Development Kit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

NOT_FOR_COMPILER=	xlc

REPLACE_PERL=		doc/gdoc

DOCDIR=		${PREFIX}/share/doc/opencdk
EGDIR=		${PREFIX}/share/examples/opencdk
HTMLDIR=	${PREFIX}/share/doc/html/opencdk

PKGCONFIG_OVERRIDE=	src/opencdk.pc.in

INSTALLATION_DIRS=	${DOCDIR} ${HTMLDIR} ${EGDIR}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS ${DESTDIR}${DOCDIR}
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.gpg *.c ${DESTDIR}${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
