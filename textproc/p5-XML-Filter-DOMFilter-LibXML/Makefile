# $NetBSD: Makefile,v 1.12 2016/02/18 04:41:34 wen Exp $

DISTNAME=	XML-Filter-DOMFilter-LibXML-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-DOMFilter-LibXML/
COMMENT=	Perl5 module SAX filter allowing DOM processing

BUILD_DEPENDS=	p5-XML-SAX-Writer>=0:../../textproc/p5-XML-SAX-Writer
DEPENDS+=	p5-XML-LibXML>=1.53:../../textproc/p5-XML-LibXML

EXTRACT_USING=	gtar

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/XML/Filter/DOMFilter/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
