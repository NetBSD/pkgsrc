# $NetBSD: Makefile,v 1.1.1.1 2003/09/04 13:29:30 xtraeme Exp $

DISTNAME=		Authen-SASL-2.04
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://search.cpan.org/dist/Authen-SASL/
COMMENT=		Perl module to handle SASL authentication

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Authen/SASL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
