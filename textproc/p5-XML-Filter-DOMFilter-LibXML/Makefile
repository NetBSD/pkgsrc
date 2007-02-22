# $NetBSD: Makefile,v 1.1.1.1 2007/02/22 12:46:26 seb Exp $

DISTNAME=	XML-Filter-DOMFilter-LibXML-0.02
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
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
