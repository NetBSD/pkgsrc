# $NetBSD: Makefile,v 1.35 2020/06/02 08:22:55 adam Exp $
#

DISTNAME=		xmlsec1-1.2.25
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		https://www.aleksey.com/xmlsec/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.aleksey.com/xmlsec/
COMMENT=		XML signature and encryption library
LICENSE=		mit AND mpl-1.1 # plus advertising clause

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-gcrypt.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-gnutls.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-nss.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec-openssl.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xmlsec.pc.in

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-gnutls
CONFIGURE_ARGS+=	--with-libxml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-libxslt=${BUILDLINK_PREFIX.libxslt}
CONFIGURE_ARGS+=	--with-gcrypt=${BUILDLINK_PREFIX.libgcrypt}

TEST_TARGET=	check

.include "../../devel/libltdl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.4.0
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=		libxml2>=2.7.4
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
