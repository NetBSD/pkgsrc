# $NetBSD: Makefile,v 1.3 2003/04/27 14:32:48 cjep Exp $
#

DISTNAME=		IO-Interface-0.97
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ioi
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		he@netbsd.org
COMMENT=		IO-Interface - get and set interface characteristics

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Interface/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
