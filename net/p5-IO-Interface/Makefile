# $NetBSD: Makefile,v 1.8 2005/04/11 21:46:53 tv Exp $
#

DISTNAME=		IO-Interface-0.98
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ioi
PKGREVISION=		1
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~lds/IO-Interface-0.98/
COMMENT=		IO-Interface - get and set interface characteristics

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
