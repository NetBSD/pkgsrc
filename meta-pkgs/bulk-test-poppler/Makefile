# $NetBSD: Makefile,v 1.1 2024/10/29 14:37:34 nia Exp $

DISTNAME=	bulk-test-poppler-20241029
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for testing Poppler

META_PACKAGE=	yes

RESTRICTED=		Just for test build purposes
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

DEPENDS+=	calibre-[0-9]*:../../misc/calibre
DEPENDS+=	cups-filters-[0-9]*:../../print/cups-filters
DEPENDS+=	gimp-[0-9]*:../../graphics/gimp
DEPENDS+=	gnome-tracker-miners-[0-9]*:../../sysutils/gnome-tracker-miners
DEPENDS+=	inkscape-[0-9]*:../../graphics/inkscape
DEPENDS+=	libreoffice-[0-9]*:../../misc/libreoffice
DEPENDS+=	krita-[0-9]*:../../graphics/krita
DEPENDS+=	pdf2djvu-[0-9]*:../../print/pdf2djvu
DEPENDS+=	pdf2svg-[0-9]*:../../converters/pdf2svg
DEPENDS+=	pdfgrep-[0-9]*:../../textproc/pdfgrep
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	xournalpp-[0-9]*:../../editors/xournalpp
DEPENDS+=	zathura-pdf-poppler-[0-9]*:../../print/zathura-pdf-poppler

.include "../../mk/bsd.pkg.mk"
