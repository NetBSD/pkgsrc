# $NetBSD: Makefile,v 1.14 2003/09/17 16:52:10 seb Exp $

DISTNAME=	Storable-2.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl extension module for persistent data storage

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
