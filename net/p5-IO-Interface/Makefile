# $NetBSD: Makefile,v 1.4 2003/07/17 22:51:32 grant Exp $
#

DISTNAME=		IO-Interface-0.97
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ioi
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@NetBSD.org
COMMENT=		IO-Interface - get and set interface characteristics

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
