# $NetBSD: Makefile,v 1.2 2002/10/13 22:10:13 seb Exp $

DISTNAME=	Error-0.15
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5err
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Error/}

MAINTAINER=	cjs@netbsd.org
COMMENT=	Perl extension module for try/throw/catch exception handling

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Error/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
