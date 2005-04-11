# $NetBSD: Makefile,v 1.12 2005/04/11 21:45:32 tv Exp $

DISTNAME=	IO-Stty-.02
PKGNAME=	p5-IO-stty-0.02
SVR4_PKGNAME=	p5ist
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl class for I/O on tty devices

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Stty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
