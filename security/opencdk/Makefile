# $NetBSD: Makefile,v 1.20 2006/09/10 20:24:01 wiz Exp $

DISTNAME=	opencdk-0.5.9
CATEGORIES=	security devel
MASTER_SITES=	http://josefsson.org/gnutls/releases/opencdk/ \
		ftp://ftp.gnutls.org/pub/gnutls/opencdk/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Open Crypto Development Kit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
TEST_TARGET=		check

NOT_FOR_COMPILER=	xlc

REPLACE_PERL=		doc/gdoc

DOCDIR=		${PREFIX}/share/doc/opencdk
EGDIR=		${PREFIX}/share/examples/opencdk
HTMLDIR=	${PREFIX}/share/doc/html/opencdk

pre-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/DETAILS ${DOCDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA}	${WRKSRC}/doc/opencdk-api.html ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/tests && ${INSTALL_DATA} *.gpg *.c ${EGDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
