# $NetBSD: Makefile,v 1.5 2001/12/11 03:42:50 wiz Exp $
#

DISTNAME=	doc2html
PKGNAME=	doc2html-3.0
CATEGORIES=	converters
MASTER_SITES=	http://www.htdig.org/files/contrib/parsers/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.htdig.org
COMMENT=	PERL external filter for htdig to convert numerous doc formats to HTML

DEPENDS+=	xlhtml-[0-9]*:../../converters/xlHtml
DEPENDS+=	rtf2html-[0-9]*:../../converters/rtf2html
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

USE_PERL5=	YES

do-build:
.for CVTR in doc2html pdf2html
	${SED} -e "s%@@LOCALBASE@@%${LOCALBASE}%g" \
		-e "s%/usr/bin/perl%${PERL5}%g" \
		-e "s%/bin/sed%${SED}%g" \
		-e "s%@@X11BASE@@%${X11BASE}%g" < ${WRKSRC}/${CVTR}.pl \
		> ${WRKSRC}/${CVTR}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doc2html ${PREFIX}/bin/doc2html
	${INSTALL_SCRIPT} ${WRKSRC}/pdf2html ${PREFIX}/bin/pdf2html

.include "../../mk/bsd.pkg.mk"
