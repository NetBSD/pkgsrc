# $NetBSD: Makefile,v 1.9 2005/02/24 22:38:41 jlam Exp $

DISTNAME=	Exception-Class-1.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exception/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~drolsky/Exception-Class/
COMMENT=	Perl5 module implementing real exception classes

DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Devel-StackTrace>=1.10:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-Test-Simple>=0.46:../../devel/p5-Test-Simple

USE_BUILDLINK3=		yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Exception/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
