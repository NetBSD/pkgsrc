# $NetBSD: Makefile,v 1.65 2008/04/20 15:48:12 tonnerre Exp $

DISTNAME=	xpdf-3.02
PKGNAME=	xpdf-3.02pl2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/xpdf/} \
		http://gd.tuwien.ac.at/publishing/xpdf/
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	xpdf-3.02pl1.patch xpdf-3.02pl2.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Display tool for PDF files

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

CONFLICTS=	xpdf-crypto-[0-9]*

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-freetype2-includes=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CONFIGURE_ARGS+=	--with-t1-includes=${BUILDLINK_PREFIX.t1lib}/include
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}
MAKE_ENV+=		SED=${SED:Q} ECHO=${ECHO:Q}

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

EGDIR=			${PREFIX}/share/examples/xpdf
CONF_FILES=		${EGDIR}/xpdfrc ${PKG_SYSCONFDIR}/xpdfrc

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	doc/pdffonts.1 doc/pdfimages.1 doc/pdfinfo.1
SUBST_FILES.paths+=	doc/pdftoppm.1 doc/pdftops.1 doc/pdftotext.1
SUBST_FILES.paths+=	doc/sample-xpdfrc doc/xpdf.1 doc/xpdfrc.5
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

OWN_DIRS=		share/xpdf

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.2.1

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)
CXXFLAGS:=	${CXXFLAGS:N-O[0-9]*}
.endif
