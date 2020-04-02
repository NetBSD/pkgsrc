# $NetBSD: Makefile,v 1.111 2020/04/02 06:42:02 wiz Exp $

.include "Makefile.common"

PKGREVISION=	1

BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--with-html-subdir=libxslt

PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in
TEST_TARGET=		check

# fix PR 55123 - leading whitespace breaks manpage
SUBST_CLASSES+=		man
SUBST_FILES.man=	doc/xsltproc.1
SUBST_STAGE.man=	post-build
SUBST_MESSAGE.man=	Clean up manpages.
SUBST_SED.man+=		-e 's,^[	 ]*,,'
SUBST_SED.man+=		-e '/^$$/d'

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MIRIX-5.*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
