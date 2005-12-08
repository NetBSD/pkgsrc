# $NetBSD: Makefile,v 1.39.2.1 2005/12/08 09:03:11 seb Exp $

DISTNAME=	xpdf-3.01
PKGNAME=	${DISTNAME}pl1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/} \
		http://gd.tuwien.ac.at/publishing/xpdf/

PATCH_SITES=		${MASTER_SITES}
PATCHFILES=		xpdf-3.01pl1.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Display tool for PDF files

DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

CONFLICTS=	xpdf-crypto-[0-9]*

USE_PKGINSTALL=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-freetype2-includes=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CONFIGURE_ARGS+=	--with-t1-includes=${BUILDLINK_PREFIX.t1lib}/include
CONFIGURE_ENV+=		CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=		SED="${SED}" ECHO="${ECHO}"

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE) && ${PAPERSIZE} == "A4"
CONFIGURE_ARGS+=	--enable-a4-paper
.endif

EGDIR=			${PREFIX}/share/examples/xpdf
CONF_FILES=		${EGDIR}/xpdfrc ${PKG_SYSCONFDIR}/xpdfrc

post-patch:
	@cd ${WRKSRC}/doc && \
	for f in *.1 *.5; do \
		${MV} $${f} $${f}.orig; \
		${SED} ${FILES_SUBST_SED} $${f}.orig > $${f}; \
	done

# Used by supplemental packages.
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)
CXXFLAGS:=	${CXXFLAGS:N-O[0-9]*}
.endif
