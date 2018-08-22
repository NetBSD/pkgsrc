# $NetBSD: Makefile,v 1.28 2018/08/22 09:46:46 wiz Exp $

DISTNAME=	html2wml-0.4.8r2
PKGNAME=	html2wml-0.4.8.2
PKGREVISION=	10
CATEGORIES=	textproc converters
MASTER_SITES=	http://maddingue.free.fr/softwares/download/Html2Wml/html2wml-0.4.x/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=htmlwml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://maddingue.free.fr/softwares/html2wml.html
COMMENT=	On-the-fly HTML to WML conversion

DEPENDS+=	p5-libwww>=5.53:../../www/p5-libwww
DEPENDS+=	p5-XML-Parser>=2.30:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Text-Template>=1.31:../../textproc/p5-Text-Template
DEPENDS+=	p5-XML-LibXML>=1.31:../../textproc/p5-XML-LibXML

NO_BUILD=	yes

USE_TOOLS+=	perl:run
REPLACE_PERL=	${WRKSRC}/html2wml.cgi

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/html2wml.cgi ${DESTDIR}${PREFIX}/bin/html2wml
	${INSTALL_MAN} ${WRKSRC}/doc/html2wml.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/html2wml.1

.include "../../mk/bsd.pkg.mk"
