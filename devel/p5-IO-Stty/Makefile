# $NetBSD: Makefile,v 1.8 2003/06/02 01:20:29 jschauma Exp $

DISTNAME=	IO-Stty-.02
PKGNAME=	p5-IO-stty-0.02
SVR4_PKGNAME=	p5ist
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl class for I/O on tty devices

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Stty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
