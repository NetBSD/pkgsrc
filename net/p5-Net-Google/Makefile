# $NetBSD: Makefile,v 1.1.1.1 2004/04/09 11:31:55 grant Exp $

DISTNAME=		Net-Google-0.61
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl module for accessing Google search engine

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Google/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
