# $NetBSD: Makefile,v 1.28 2018/08/22 09:43:05 wiz Exp $

DISTNAME=	doc2html
PKGNAME=	doc2html-3.0
PKGREVISION=	10
CATEGORIES=	converters
#MASTER_SITES=	http://www.htdig.org/files/contrib/parsers/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.htdig.org/
COMMENT=	PERL external filter for htdig to convert numerous doc formats to HTML

DEPENDS+=	xlhtml-[0-9]*:../../converters/xlhtml
DEPENDS+=	rtf2html-[0-9]*:../../converters/rtf2html
DEPENDS+=	xpdf-[0-9]*:../../print/xpdf
DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

USE_TOOLS+=	gs:run perl:run

INSTALLATION_DIRS=	bin

do-build:
.for cvtr in doc2html pdf2html
	${SED} -e "s%@@LOCALBASE@@%${LOCALBASE}%g" \
		-e "s%/usr/bin/perl%${PERL5}%g" \
		-e "s%/bin/sed%${SED}%g" \
		-e "s%@@X11BASE@@%${X11BASE}%g" < ${WRKSRC}/${cvtr}.pl \
		> ${WRKSRC}/${cvtr}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doc2html ${DESTDIR}${PREFIX}/bin/doc2html
	${INSTALL_SCRIPT} ${WRKSRC}/pdf2html ${DESTDIR}${PREFIX}/bin/pdf2html

.include "../../mk/bsd.pkg.mk"
