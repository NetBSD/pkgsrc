# $NetBSD: Makefile,v 1.5 2004/04/27 04:59:42 snj Exp $

DISTNAME=	Exception-Class-1.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5exc
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exception/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/author/DROLSKY/Exception-Class-1.14/
COMMENT=	Perl5 module implementing real exception classes

DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Devel-StackTrace>=1.03:../../devel/p5-Devel-StackTrace

USE_BUILDLINK_ONLY=	YES
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Exception/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
