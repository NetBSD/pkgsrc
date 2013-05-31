# $NetBSD: Makefile,v 1.28 2013/05/31 12:40:25 wiz Exp $
#

DISTNAME=	IO-Tty-1.10
PKGNAME=	p5-${DISTNAME:C/T/t/}
PKGREVISION=	3
SVR4_PKGNAME=	p5itt
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Another Perl class for I/O on tty and pseudo-tty devices

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Tty/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
