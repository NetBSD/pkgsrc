# $NetBSD: Makefile,v 1.1.1.1 2004/11/12 06:20:31 erh Exp $

DISTNAME=	XML-Filter-DetectWS-0.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-DetectWS-0.01/
COMMENT=	PerlSAX filter that detects ignorable whitespace

DEPENDS+=	p5-XML-Filter-SAXT>=0.01:../../textproc/p5-XML-Filter-SAXT

USE_BUILDLINK3=		YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Filter/DetectWS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
