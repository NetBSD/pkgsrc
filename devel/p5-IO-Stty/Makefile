# $NetBSD: Makefile,v 1.10 2004/04/25 03:51:10 minskim Exp $

DISTNAME=	IO-Stty-.02
PKGNAME=	p5-IO-stty-0.02
SVR4_PKGNAME=	p5ist
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl class for I/O on tty devices

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Stty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
