# $NetBSD: Makefile,v 1.12 2003/06/02 01:20:22 jschauma Exp $

DISTNAME=	Storable-2.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5sto
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl extension module for persistent data storage

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_ARCHLIB}/auto/Storable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
