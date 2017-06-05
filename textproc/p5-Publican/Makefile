# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:44 ryoon Exp $
#

DISTNAME=	Publican-v4.3.1
PKGNAME=	p5-${DISTNAME:S/v//1}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://fedorahosted.org/releases/p/u/publican/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://fedorahosted.org/publican/
COMMENT=	Single source publishing tool based on DocBook XML
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
BUILD_DEPENDS+=	p5-Devel-Cover-[0-9]*:../../devel/p5-Devel-Cover
DEPENDS+=	p5-XML-TreeBuilder-[0-9]*:../../textproc/p5-XML-TreeBuilder
DEPENDS+=	p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-Text-CSV_XS-[0-9]*:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Syntax-Highlight-Engine-Kate-[0-9]*:../../textproc/p5-Syntax-Highlight-Engine-Kate
DEPENDS+=	p5-String-Similarity-[0-9]*:../../textproc/p5-String-Similarity
DEPENDS+=	p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
DEPENDS+=	p5-Locale-PO-[0-9]*:../../devel/p5-Locale-PO
DEPENDS+=	p5-Locale-Maketext-Gettext-[0-9]*:../../textproc/p5-Locale-Maketext-Gettext
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-FormatText-WithLinks-AndTables-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks-AndTables
DEPENDS+=	p5-HTML-FormatText-WithLinks-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks
DEPENDS+=	p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-File-Inplace-[0-9]*:../../sysutils/p5-File-Inplace
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-DateTime-Format-DateParse-[0-9]*:../../time/p5-DateTime-Format-DateParse
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Config-Simple-[0-9]*:../../sysutils/p5-Config-Simple
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-File-Find-Rule-[0-9]*:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-Lingua-EN-Syllable-[0-9]*:../../textproc/p5-Lingua-EN-Syllable
DEPENDS+=	p5-Lingua-EN-Fathom-[0-9]*:../../textproc/p5-Lingua-EN-Fathom
DEPENDS+=	p5-Locale-Msgfmt-[0-9]*:../../devel/p5-Locale-Msgfmt
DEPENDS+=	p5-Locale-Maketext-Lexicon-[0-9]*:../../misc/p5-Locale-Maketext-Lexicon

# TODO: Look for the dependencies in Build.PL.

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
