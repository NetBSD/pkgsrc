# $NetBSD: Makefile,v 1.2 2002/10/06 22:33:18 seb Exp $
#

DISTNAME=		IO-Interface-0.97
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5intf
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@netbsd.org
COMMENT=		IO-Interface - get and set interface characteristics

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
