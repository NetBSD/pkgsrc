# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 18:58:33 he Exp $

DISTNAME=	Class-Data-Inheritable-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdi
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/MSCHWERN/Class-Data-Inheritable-0.02/
COMMENT=	Inheritable, overridable class data

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Data/Inheritable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
