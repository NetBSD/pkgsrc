# $NetBSD: Makefile,v 1.17 2009/10/30 19:32:11 tnn Exp $
#

DISTNAME=		xmlsec1-1.2.13
CATEGORIES=		security
MASTER_SITES=		http://www.aleksey.com/xmlsec/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.aleksey.com/xmlsec/
COMMENT=		XML signature and encryption library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-gnutls.pc.in
#PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-nss.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-openssl.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec.pc.in
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--without-openssl
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-gnutls

.include "../../security/openssl/buildlink3.mk"
#.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
