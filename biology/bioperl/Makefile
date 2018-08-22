# $NetBSD: Makefile,v 1.36 2018/08/22 09:42:59 wiz Exp $

DISTNAME=	BioPerl-1.007002
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	biology perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bioperl.org/
COMMENT=	Perl tools for computational molecular biology
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.19.6,p5-Module-Build>0.42}:../../devel/p5-Module-Build
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most

DEPENDS+=	p5-Algorithm-Munkres-[0-9]*:../../math/p5-Algorithm-Munkres
DEPENDS+=	p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare
DEPENDS+=	p5-Bio-ASN1-EntrezGene-[0-9]*:../../biology/p5-Bio-ASN1-EntrezGene
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-Convert-Binary-C-[0-9]*:../../devel/p5-Convert-Binary-C
#DEPENDS+=	{perl>=5,p5-DB_File-[0-9]*}:../../databases/p5-DB_File
DEPENDS+=	p5-Data-Stag>=0.11:../../devel/p5-Data-Stag
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error
#DEPENDS+=	{perl>=5.10.1,p5-ExtUtils-Manifest>=1.52}:../../devel/p5-ExtUtils-Manifest
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-Graph>=0.50:../../devel/p5-Graph
DEPENDS+=	p5-GraphViz-[0-9]*:../../graphics/p5-GraphViz
DEPENDS+=	p5-HTML-Parser>=3:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-TableExtract-[0-9]*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-PostScript-[0-9]*:../../print/p5-PostScript
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-SVG-Graph>=0.01:../../graphics/p5-SVG-Graph
DEPENDS+=	p5-SVG>=2.26:../../graphics/p5-SVG
DEPENDS+=	p5-Set-Scalar-[0-9]*:../../devel/p5-Set-Scalar
DEPENDS+=	p5-Sort-Naturally-[0-9]*:../../devel/p5-Sort-Naturally
DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel
#DEPENDS+=	{perl>=5.8.1,p5-Storable>=2.05}:../../devel/p5-Storable
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-SAX-Writer-[0-9]*:../../textproc/p5-XML-SAX-Writer
DEPENDS+=	p5-XML-SAX>=0.15:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-XML-Twig-[0-9]*:../../textproc/p5-XML-Twig
DEPENDS+=	p5-XML-Writer>=0.4:../../textproc/p5-XML-Writer
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-libxml-[0-9]*:../../textproc/p5-libxml

# Suggested
DEPENDS+=	p5-XML-DOM>=0:../../textproc/p5-XML-DOM
# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff

USE_TOOLS+=		pax

REPLACE_PERL+=		scripts/*/*.pl Bio/LiveSeq/Chain.pm

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Bio/.packlist

INSTALLATION_DIRS=	share/examples/bioperl

post-install:
	cd ${WRKSRC}/examples && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/bioperl

.include "options.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
