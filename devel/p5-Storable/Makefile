# $NetBSD: Makefile,v 1.10 2002/10/13 22:22:47 seb Exp $

DISTNAME=	Storable-2.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl extension module for persistent data storage

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_ARCHLIB}/auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
