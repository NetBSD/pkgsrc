# $NetBSD: Makefile,v 1.1.1.1 2009/08/03 23:37:33 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	texlive-pdftools-2008
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	PDF-related utilities in TeX Live

CONFLICTS+=	teTeX-bin<=3.0nb34
CONFLICTS+=	texlive-tetex<=2008nb1
DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=	web2c-[0-9]*:../../print/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ELEMENTS=	${DISTNAME}/texk/tetex \
			${DISTNAME}/texk/texlive/linked_scripts \
			${DISTNAME}/utils/pdfopen

CONFIGURE_DIRS=	utils/pdfopen
GNU_CONFIGURE=	yes
USE_TOOLS+=	sh:run

REPLACE_PERL=	texk/texlive/linked_scripts/e2pall.pl \
		texk/texlive/linked_scripts/epstopdf.pl \
		texk/texlive/linked_scripts/pdfatfi.pl
REPLACE_SH=	texk/texlive/linked_scripts/ps4pdf

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/texk/texlive/linked_scripts/e2pall.pl \
		${DESTDIR}${PREFIX}/bin/e2pall
	${INSTALL_SCRIPT} ${WRKSRC}/texk/texlive/linked_scripts/epstopdf.pl \
		${DESTDIR}${PREFIX}/bin/epstopdf
	${INSTALL_SCRIPT} ${WRKSRC}/texk/texlive/linked_scripts/pdfatfi.pl \
		${DESTDIR}${PREFIX}/bin/pdfatfi
	${INSTALL_SCRIPT} ${WRKSRC}/texk/texlive/linked_scripts/ps4pdf \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/texk/tetex/e2pall.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/e2pall.1
	${INSTALL_MAN} ${WRKSRC}/texk/tetex/epstopdf.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/epstopdf.1

.include "../../mk/bsd.pkg.mk"
