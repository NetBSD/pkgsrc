# $NetBSD: Makefile,v 1.8 2003/07/21 16:43:40 martti Exp $
#

DISTNAME=      	Parse-Yapp-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p6pya
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 LALR parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
