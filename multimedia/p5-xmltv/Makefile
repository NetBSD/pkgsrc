# $NetBSD: Makefile,v 1.28 2011/08/14 13:47:56 obache Exp $

DISTNAME=	xmltv-0.5.56
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmltv/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmltv.org/wiki/
COMMENT=	Set of utilities to manage your TV viewing
LICENSE=	gnu-gpl-v2

# needed
DEPENDS+=	p5-Date-Manip>=5.42a:../../devel/p5-Date-Manip
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-XML-Parser>=2.34:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-Twig>=3.10:../../textproc/p5-XML-Twig
DEPENDS+=	p5-XML-Writer>=0.600:../../textproc/p5-XML-Writer
DEPENDS+=	{perl>=5.10,p5-Memoize-[0-9]*}:../../devel/p5-Memoize
DEPENDS+=	{perl>=5.10,p5-Storable>=2.04}:../../devel/p5-Storable
DEPENDS+=	p5-libwww>=5.65:../../www/p5-libwww
# recommended
DEPENDS+=	p5-Lingua-EN-Numbers-Ordinate-[0-9]*:../../textproc/p5-Lingua-EN-Numbers-Ordinate
DEPENDS+=	p5-Lingua-Preferred>=0.2.4:../../textproc/p5-Lingua-Preferred
DEPENDS+=	p5-Term-ProgressBar>=2.03:../../devel/p5-Term-ProgressBar
DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
# needed by se, uk grabbers
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
# needed by uk grabber
DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-HTTP-Cache-Transparent>=1.0:../../www/p5-HTTP-Cache-Transparent
# needed by us grabbers
DEPENDS+=	p5-SOAP-Lite-[0-9]*:../../net/p5-SOAP-Lite
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-HTML-TableExtract-[0-9]*:../../www/p5-HTML-TableExtract
DEPENDS+=	p5-WWW-Mechanize>=1.02:../../www/p5-WWW-Mechanize
# needed by DirectTV grabbers in us
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
# needed by de, dk, es, fi, fr, huro, jp, nl, pt grabbers
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
# needed to grab for some european countries (epgdata.com)
DEPENDS+=	p5-DateTime-Format-Strptime-[0-9]*:../../time/p5-DateTime-Format-Strptime
# needed by jp grabber
DEPENDS+=	p5-Text-Kakasi-[0-9]*:../../textproc/p5-Text-Kakasi
# needed by se grabber
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-IO-Compress-[0-9]*:../../devel/p5-IO-Compress
DEPENDS+=	p5-HTTP-Cache-Transparent-[0-9]*:../../www/p5-HTTP-Cache-Transparent
# needed by pt grabber
DEPENDS+=	p5-Unicode-UTF8simple-[0-9]*:../../converters/p5-Unicode-UTF8simple
# needed by is grabbers
DEPENDS+=	p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT
DEPENDS+=	p5-XML-DOM-[0-9]*:../../textproc/p5-XML-DOM
# Tk::TableMatrix missing for tv_check (report exceptions & changes in schedule)

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/XMLTV/.packlist
USE_TOOLS+=	perl

MAKE_PARAMS+=	PREFIX=${PREFIX:Q}
PLIST_SUBST+=	DISTNAME=${DISTNAME:Q}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
