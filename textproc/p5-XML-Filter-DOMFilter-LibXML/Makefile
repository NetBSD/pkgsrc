# $NetBSD: Makefile,v 1.8 2013/05/31 12:42:19 wiz Exp $

DISTNAME=	XML-Filter-DOMFilter-LibXML-0.02
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-DOMFilter-LibXML/
COMMENT=	Perl5 module SAX filter allowing DOM processing

DEPENDS+=	p5-XML-LibXML>=1.53:../../textproc/p5-XML-LibXML

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/XML/Filter/DOMFilter/LibXML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
