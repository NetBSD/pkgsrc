# $NetBSD: Makefile,v 1.8 2006/02/05 23:10:47 joerg Exp $
#

DISTNAME=		xmlsec1-1.2.6
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.aleksey.com/xmlsec/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.aleksey.com/xmlsec/
COMMENT=		XML signature and encryption library

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-gnutls.pc.in
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-nss.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-openssl.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec.pc.in
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--without-openssl
CONFIGURE_ARGS+=	--without-gnutls

.include "../../security/openssl/buildlink3.mk"
#.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
