# $NetBSD: Makefile,v 1.7 2002/10/13 22:22:50 seb Exp $

DISTNAME=	IO-Stty-.02
PKGNAME=	p5-IO-stty-0.02
SVR4_PKGNAME=	p5ist
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl class for I/O on tty devices

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Stty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
