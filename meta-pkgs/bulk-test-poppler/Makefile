# $NetBSD: Makefile,v 1.5 2026/01/04 11:40:55 wiz Exp $

DISTNAME=	bulk-test-poppler-20260104
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for testing Poppler

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

# needs podofo<1, but scribus needs >=1
#DEPENDS+=	calibre-[0-9]*:../../misc/calibre
DEPENDS+=	cups-filters-[0-9]*:../../print/cups-filters
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	gnome-tracker-miners-[0-9]*:../../sysutils/gnome-tracker-miners
DEPENDS+=	inkscape-[0-9]*:../../graphics/inkscape
DEPENDS+=	libreoffice-[0-9]*:../../misc/libreoffice
DEPENDS+=	krita-[0-9]*:../../graphics/krita
DEPENDS+=	pdf2djvu-[0-9]*:../../print/pdf2djvu
DEPENDS+=	pdf2svg-[0-9]*:../../converters/pdf2svg
DEPENDS+=	pdfgrep-[0-9]*:../../textproc/pdfgrep
DEPENDS+=	scribus-[0-9]*:../../print/scribus
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	xournalpp-[0-9]*:../../editors/xournalpp
DEPENDS+=	zathura-pdf-poppler-[0-9]*:../../print/zathura-pdf-poppler

.include "../../mk/bsd.pkg.mk"
