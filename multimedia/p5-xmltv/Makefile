# $NetBSD: Makefile,v 1.1.1.1 2004/10/20 18:56:28 adrianp Exp $

DISTNAME=	xmltv-0.5.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmltv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://membled.com/work/apps/xmltv/
COMMENT=	Set of utilities to manage your TV viewing

DEPENDS+=	p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-Twig>=3.10:../../textproc/p5-XML-Twig
DEPENDS+=	p5-XML-Writer>=0.4.6:../../textproc/p5-XML-Writer
DEPENDS+=	p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+=	p5-libwww>=5.65:../../www/p5-libwww
DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
DEPENDS+=	p5-Memoize-[0-9]*:../../devel/p5-Memoize
DEPENDS+=	p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=	p5-Term-ProgressBar-[0-9]*:../../devel/p5-Term-ProgressBar
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-HTML-TableExtract-[0-9]*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-Text-Kakasi-[0-9]*:../../textproc/p5-Text-Kakasi
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-LinkExtractor-[0-9]*:../../www/p5-HTML-LinkExtractor

PERL5_REQD?=	5.6.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XMLTV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
