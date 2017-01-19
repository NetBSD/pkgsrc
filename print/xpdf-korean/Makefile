# $NetBSD: Makefile,v 1.26 2017/01/19 18:52:23 agc Exp $

DISTNAME=	xpdf-korean-2011-sep-02
PKGNAME=	xpdf-korean-20110902
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
MASTER_SITES+=	http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Korean
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf
DEPENDS+=	baekmuk-ttf>=1.0:../../fonts/baekmuk-ttf

WRKSRC=		${WRKDIR}/xpdf-korean
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/korean/CMap

SUBST_CLASSES+=		xpdfrc
SUBST_MESSAGE.xpdfrc=	Adjusting xpdfrc wedge.
SUBST_STAGE.xpdfrc=	post-patch
SUBST_FILES.xpdfrc=	add-to-xpdfrc
SUBST_SED.xpdfrc+=	-e 's,/usr/\.\.\.\.,'${PREFIX}'/share/fonts/X11/TTF,' \
			-e 's:/usr/local:'${PREFIX}':g' \
			-e '/^.fontFileCC/{;s/^.//;s/.$$//;};'
do-install:
	${INSTALL_DATA} ${WRKSRC}/Adobe-Korea1.cidToUnicode \
	    ${WRKSRC}/ISO-2022-KR.unicodeMap ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/korean
	${INSTALL_DATA} ${WRKSRC}/CMap/* \
	    ${DESTDIR}${PREFIX}/share/xpdf/korean/CMap

.include "../../mk/bsd.pkg.mk"
