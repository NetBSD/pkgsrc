# $NetBSD: Makefile,v 1.29 2022/06/28 11:36:09 wiz Exp $
#

DISTNAME=	dtdparse-2.0beta6
PKGREVISION=	19
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dtdparse/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://dtdparse.sourceforge.net/
COMMENT=	Reads an SGML or XML DTD and constructs an XML database

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM
DEPENDS+=	p5-Text-DelimMatch-[0-9]*:../../textproc/p5-Text-DelimMatch

DOCDIR=		${PREFIX}/share/doc/dtdparse
EGDIR=		${PREFIX}/share/examples/dtdparse
XMLDIR=		${PREFIX}/share/xml/dtdparse
XML_CATALOGS=	${XMLDIR}/catalog
SCRIPTS=	dtdflatten dtdformat dtdparse \
		tools/contentmodel tools/dtdstats tools/elements

INSTALLATION_DIRS=	bin ${PERL5_INSTALLVENDORLIB}/XML/DTDParse \
			${DOCDIR} ${EGDIR} ${XMLDIR}

do-build:
	cd ${WRKSRC}; \
		${PERL5} -pi -e 's,/usr/local/bin/perl5,${PERL5},' ${SCRIPTS}
	${PERL5} -pi -e 's,modules/,XML/DTDParse/,' ${WRKSRC}/dtdformat

do-install:
	cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/XML/DTDParse/*.pm ${WRKSRC}/modules/*.pl \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/XML/DTDParse
	${INSTALL_DATA} ${WRKSRC}/dtd.dtd ${DESTDIR}${XMLDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${DESTDIR}${XMLDIR}/catalog

post-install:
	cd ${WRKSRC}/sample; \
		${INSTALL_DATA} sample* simple* ${DESTDIR}${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} README WhatsNew ${DESTDIR}${DOCDIR}

.include "../../lang/perl5/module.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
