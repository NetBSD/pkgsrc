# $NetBSD: Makefile,v 1.13 2002/12/07 17:49:43 drochner Exp $
# 

DISTNAME=	xpdf-2.01
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		${MASTER_SITE_SUNSITE:=apps/graphics/viewers/X/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Display tool for PDF files

DEPENDS+=	ghostscript-fonts-[0-9]*:../../fonts/ghostscript-fonts

CONFLICTS=	xpdf-crypto-[0-9]*

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
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

.include "../../fonts/t1lib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-mipsel)
CXXFLAGS:=	${CXXFLAGS:N-O[0-9]*}
.endif
