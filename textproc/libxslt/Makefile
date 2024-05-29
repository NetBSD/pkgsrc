# $NetBSD: Makefile,v 1.132 2024/05/29 16:34:37 adam Exp $

PKGREVISION= 1
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
.  if ${OS_VARIANT} == Solaris
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./libxslt.syms
.  else
BUILDLINK_TRANSFORM+=	opt:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms
.  endif
.endif

.if ${USE_CROSS_COMPILE:tl} == "yes"
# Both libgcrypt and libxml2 install scripts in the _target_ system,
# that are expected to be run on the _build_ system when compiling
# downstream dependencies like libxslt.  I don't see a way to use
# pkg-config or anything reasonable to override this, so, we do the
# nonsense thing instead of executing cross-compiled `binaries' on the
# build system.
CONFIGURE_ARGS+=	LIBGCRYPT_CONFIG=${CROSS_DESTDIR:Q}${LOCALBASE:Q}/bin/libgcrypt-config
CONFIGURE_ARGS+=	XML_CONFIG=${CROSS_DESTDIR:Q}${LOCALBASE:Q}/bin/xml2-config
.endif

.include "../../security/libgcrypt/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
