# $NetBSD: Makefile,v 1.3 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=	Authen-SASL-2.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://search.cpan.org/dist/Authen-SASL/
COMMENT=	Perl module to handle SASL authentication

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Authen/SASL/.packlist

.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
