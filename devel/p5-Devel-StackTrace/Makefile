# $NetBSD: Makefile,v 1.2 2003/04/27 14:31:52 cjep Exp $
#

DISTNAME=		Devel-StackTrace-1.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dst
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for stack trace and stack trace frame objects

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Devel/StackTrace/.packlist

DEPENDS+=	p5-Test-Simple>=0.46:../p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
