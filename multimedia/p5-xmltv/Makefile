# $NetBSD: Makefile,v 1.11 2005/06/24 21:14:36 wiz Exp $

DISTNAME=	xmltv-0.5.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmltv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://membled.com/work/apps/xmltv/
COMMENT=	Set of utilities to manage your TV viewing

# needed
DEPENDS+=	p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-Twig>=3.10:../../textproc/p5-XML-Twig
DEPENDS+=	p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+=	p5-XML-Writer>=0.4.6:../../textproc/p5-XML-Writer
DEPENDS+=	p5-Memoize-[0-9]*:../../devel/p5-Memoize
DEPENDS+=	p5-Storable>=2.04:../../devel/p5-Storable
# recommended
DEPENDS+=	p5-Lingua-EN-Numbers-Ordinate-[0-9]*:../../textproc/p5-Lingua-EN-Numbers-Ordinate
DEPENDS+=	p5-Lingua-Preferred>=0.2.4:../../textproc/p5-Lingua-Preferred
DEPENDS+=	p5-Term-ProgressBar>=2.03:../../devel/p5-Term-ProgressBar
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
# needed by se, uk grabbers
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
# needed by uk grabber
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
# needed by us grabbers
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-HTML-TableExtract-[0-9]*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-WWW-Mechanize>=1.02:../../www/p5-WWW-Mechanize
# needed by de, dk, es, fi, fr, huro, jp, nl, pt grabbers
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
# needed by jp grabber
DEPENDS+=	p5-Text-Kakasi-[0-9]*:../../textproc/p5-Text-Kakasi
# needed by se grabber
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-HTTP-Cache-Transparent-[0-9]*:../../www/p5-HTTP-Cache-Transparent

PERL5_REQD?=	5.6.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XMLTV/.packlist

MAKE_PARAMS+=	PREFIX=${PREFIX:Q}
PLIST_SUBST+=	DISTNAME=${DISTNAME}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
