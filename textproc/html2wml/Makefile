# $NetBSD: Makefile,v 1.33 2026/11/22 20:35:57 drixter Exp $

DISTNAME=	html2wml-0.4.11
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlwml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://maddingue.free.fr/softwares/html2wml.html
COMMENT=	On-the-fly HTML to WML conversion
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-libwww>=5.53:../../www/p5-libwww
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Text-Template>=1.31:../../textproc/p5-Text-Template
DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-CGI>=5.02:../../www/p5-CGI
DEPENDS+=	p5-HTML-Parser>=3.87:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI>=5.40:../../www/p5-URI

NO_BUILD=	yes

USE_TOOLS+=	perl:run
REPLACE_PERL=	html2wml.cgi

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2wml.cgi ${DESTDIR}${PREFIX}/bin/html2wml
	${INSTALL_MAN} ${WRKSRC}/doc/html2wml.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/html2wml.1

.include "../../mk/bsd.pkg.mk"
