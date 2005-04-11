# $NetBSD: Makefile,v 1.4 2005/04/11 21:46:54 tv Exp $

DISTNAME=		Net-Google-0.61
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		net perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl module for accessing Google search engine

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Google/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
