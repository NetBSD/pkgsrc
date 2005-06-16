# $NetBSD: Makefile,v 1.13 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	doc2html
PKGNAME=	doc2html-3.0
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	http://www.htdig.org/files/contrib/parsers/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.htdig.org/
COMMENT=	PERL external filter for htdig to convert numerous doc formats to HTML

DEPENDS+=	xlhtml-[0-9]*:../../converters/xlhtml
DEPENDS+=	rtf2html-[0-9]*:../../converters/rtf2html
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

USE_PERL5=	YES

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
	${INSTALL_SCRIPT} ${WRKSRC}/doc2html ${PREFIX}/bin/doc2html
	${INSTALL_SCRIPT} ${WRKSRC}/pdf2html ${PREFIX}/bin/pdf2html

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
