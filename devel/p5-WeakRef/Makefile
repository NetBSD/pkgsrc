# $NetBSD: Makefile,v 1.6 2003/07/17 21:32:56 grant Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5wre
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Provide weak references in Perl

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/WeakRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
