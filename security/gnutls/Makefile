# $NetBSD: Makefile,v 1.4 2003/10/18 08:10:57 jmmv Exp $
#

DISTNAME=	gnutls-0.8.7
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	ftp://ftp.gnutls.org/pub/gnutls/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnutls.org/
COMMENT=	GNU Transport Layer Security library

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

# The security/libtasn1 package provides a version that is too new to work
# fine with this version of gnutls.
CONFIGURE_ARGS+=	--with-included-libtasn

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

DOCDIR=		${PREFIX}/share/doc/gnutls
EGDIR=		${PREFIX}/share/examples/gnutls

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCDIR}
	cd ${WRKSRC}/doc/tex && ${INSTALL_DATA} *.ps *.tex *.eps ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc/examples && ${INSTALL_DATA} *.c ${EGDIR}

.include "../../archivers/liblzo/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/opencdk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
