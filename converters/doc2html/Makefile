# $NetBSD: Makefile,v 1.19 2012/10/03 00:20:10 asau Exp $
#

DISTNAME=	doc2html
PKGNAME=	doc2html-3.0
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://www.htdig.org/files/contrib/parsers/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.htdig.org/
COMMENT=	PERL external filter for htdig to convert numerous doc formats to HTML

DEPENDS+=	xlhtml-[0-9]*:../../converters/xlhtml
DEPENDS+=	rtf2html-[0-9]*:../../converters/rtf2html
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

USE_TOOLS+=	gs:run perl:run

INSTALLATION_DIRS=	bin

do-build:
.for CVTR in doc2html pdf2html
	${SED} -e "s%@@LOCALBASE@@%${LOCALBASE}%g" \
		-e "s%/usr/bin/perl%${PERL5}%g" \
		-e "s%/bin/sed%${SED}%g" \
		-e "s%@@X11BASE@@%${X11BASE}%g" < ${WRKSRC}/${CVTR}.pl \
		> ${WRKSRC}/${CVTR}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doc2html ${DESTDIR}${PREFIX}/bin/doc2html
	${INSTALL_SCRIPT} ${WRKSRC}/pdf2html ${DESTDIR}${PREFIX}/bin/pdf2html

.include "../../mk/bsd.pkg.mk"
