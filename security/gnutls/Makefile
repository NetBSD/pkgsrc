# $NetBSD: Makefile,v 1.10 2004/02/10 00:20:29 jlam Exp $

DISTNAME=	gnutls-1.0.4
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCDIR}
	cd ${WRKSRC}/doc/tex && ${INSTALL_DATA} *.ps *.tex *.eps ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${EGDIR}

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../security/opencdk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
