# $NetBSD: Makefile,v 1.9 2003/12/03 19:22:07 heinz Exp $
#

DISTNAME=      	Parse-Yapp-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pya
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 LALR parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parse/Yapp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
