# $NetBSD: Makefile,v 1.12 2003/07/17 21:32:31 grant Exp $
#

DISTNAME=	IO-Tty-1.02
PKGNAME=	p5-${DISTNAME:C/T/t/}
SVR4_PKGNAME=	p5itt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Tty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
