# $NetBSD: Makefile,v 1.126 2023/06/06 12:42:25 riastradh Exp $

.include "Makefile.common"

TOOL_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--without-python

PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in
TEST_TARGET=		check

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms

.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
