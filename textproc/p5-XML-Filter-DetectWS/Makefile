# $NetBSD: Makefile,v 1.3 2004/12/20 11:31:10 grant Exp $

DISTNAME=	XML-Filter-DetectWS-0.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-DetectWS-0.01/
COMMENT=	PerlSAX filter that detects ignorable whitespace

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Filter-SAXT>=0.01:../../textproc/p5-XML-Filter-SAXT

USE_BUILDLINK3=		YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Filter/DetectWS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
