# $NetBSD: Makefile,v 1.3 2003/04/27 13:24:33 cjep Exp $
#

DISTNAME=		Class-ReturnValue-0.51
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5clv
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for return-value object

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/ReturnValue/.packlist

DEPENDS+=		p5-Devel-StackTrace-[0-9]*:../p5-Devel-StackTrace
DEPENDS+=		p5-Test-Inline-[0-9]*:../p5-Test-Inline

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
