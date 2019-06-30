# $NetBSD: Makefile,v 1.16 2019/06/30 20:17:08 nia Exp $

DISTNAME=	XML-Filter-DOMFilter-LibXML-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Filter-DOMFilter-LibXML
COMMENT=	Perl5 module SAX filter allowing DOM processing

BUILD_DEPENDS=	p5-XML-SAX-Writer>=0:../../textproc/p5-XML-SAX-Writer
DEPENDS+=	p5-XML-LibXML>=1.53:../../textproc/p5-XML-LibXML

EXTRACT_USING=	gtar

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/XML/Filter/DOMFilter/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
