# $NetBSD: Makefile,v 1.3 2004/12/20 11:31:07 grant Exp $

DISTNAME=	Net-XWhois-0.90
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Net-XWhois/
COMMENT=	Perl5 module for Whois Client Interface

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/XWhois/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
