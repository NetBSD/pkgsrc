# $NetBSD: Makefile,v 1.84 2017/08/14 06:49:51 wiz Exp $

DISTNAME=	xpdf-3.04
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
MASTER_SITES+=	${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/xpdf/}
MASTER_SITES+=	http://gd.tuwien.ac.at/publishing/xpdf/
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xpdfreader.com/
COMMENT=	Display tool for PDF files
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts
DEPENDS+=	poppler-utils-[0-9]*:../../print/poppler-utils

CONFLICTS=	xpdf-crypto-[0-9]*

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-freetype2-includes=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CONFIGURE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}
MAKE_ENV+=		SED=${SED:Q} ECHO=${ECHO:Q}

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

EGDIR=			${PREFIX}/share/examples/xpdf
CONF_FILES=		${EGDIR}/xpdfrc ${PKG_SYSCONFDIR}/xpdfrc

SUBST_CLASSES+=		paths
#SUBST_FILES.paths=	doc/pdffonts.1 doc/pdfimages.1 doc/pdfinfo.1
#SUBST_FILES.paths+=	doc/pdftoppm.1 doc/pdftops.1 doc/pdftotext.1
SUBST_FILES.paths+=	doc/sample-xpdfrc doc/xpdf.1 doc/xpdfrc.5
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

OWN_DIRS=		share/xpdf

BUILDLINK_API_DEPENDS.freetype2+=	freetype2>=2.2.1

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)
CXXFLAGS:=	${CXXFLAGS:N-O[0-9]*}
.endif
