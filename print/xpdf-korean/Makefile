# $NetBSD: Makefile,v 1.30 2023/07/03 13:11:48 wiz Exp $

DISTNAME=	xpdf-korean-2011-sep-02
PKGNAME=	xpdf-korean-20110902
PKGREVISION=	1
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-korean.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Korean
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02<4:../../print/xpdf
DEPENDS+=	baekmuk-ttf>=1.0:../../fonts/baekmuk-ttf

WRKSRC=		${WRKDIR}/xpdf-korean
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/korean/CMap

SUBST_CLASSES+=		xpdfrc
SUBST_MESSAGE.xpdfrc=	Adjusting xpdfrc wedge.
SUBST_STAGE.xpdfrc=	pre-configure
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
