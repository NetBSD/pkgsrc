# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 14:03:20 agc Exp $
#

DISTNAME=	doc2html
PKGNAME=	doc2html-2.1
CATEGORIES=	converters
MASTER_SITES=	http://www.htdig.org/files/contrib/parsers/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.htdig.org
COMMENT=	PERL external filter for htdig to convert numerous doc formats to HTML

DEPENDS+=	xlHtml-*:../../converters/xlHtml
DEPENDS+=	rtf2html-*:../../converters/rtf2html
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	xpdf-*:../../graphics/xpdf
DEPENDS+=	catdoc-*:../../textproc/catdoc

USE_PERL5=	YES

do-build:
	${SED} -e "s%@@LOCALBASE@@%${LOCALBASE}%g" \
		-e "s%/usr/bin/perl%${PERL5}%g" \
		-e "s%/bin/sed%${SED}%g" \
		-e "s%@@X11BASE@@%${X11BASE}%g" < ${WRKSRC}/doc2html.pl \
		> ${WRKSRC}/doc2html

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doc2html ${PREFIX}/bin/doc2html

.include "../../mk/bsd.pkg.mk"
