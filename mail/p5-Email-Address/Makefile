# $NetBSD: Makefile,v 1.14 2013/09/08 07:46:18 wen Exp $

DISTNAME=	Email-Address-1.900
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Address/
COMMENT=	RFC 2822 Address Parsing and Creation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/Email/Address/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
