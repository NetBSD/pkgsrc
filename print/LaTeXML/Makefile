# $NetBSD: Makefile,v 1.3 2018/08/22 09:46:12 wiz Exp $

DISTNAME=	LaTeXML-0.8.2
PKGREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	https://dlmf.nist.gov/LaTeXML/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dlmf.nist.gov/LaTeXML/
COMMENT=	LaTeX to XML/HTML/MathML Converter
LICENSE=	public-domain

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-DB_File-[0-9]*:../../databases/p5-DB_File
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Pod-Parser-[0-9]*:../../textproc/p5-Pod-Parser
DEPENDS+=	p5-Text-Unidecode-[0-9]*:../../textproc/p5-Text-Unidecode
DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-XML-LibXSLT-[0-9]*:../../textproc/p5-XML-LibXSLT
DEPENDS+=	p5-UUID-Tiny-[0-9]*:../../devel/p5-UUID-Tiny
# can probably be reduced, but this should be a good start
DEPENDS+=	texlive-collection-latexrecommended-[0-9]*:../../meta-pkgs/texlive-collection-latexrecommended
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick

PERL5_PACKLIST=	auto/LaTeXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
