# $NetBSD: Makefile,v 1.5 2003/12/21 10:03:42 xtraeme Exp $
#

DISTNAME=	opencdk-0.5.3
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/opencdk/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	Open Crypto Development Kit

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
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

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
