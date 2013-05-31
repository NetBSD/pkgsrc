# $NetBSD: Makefile,v 1.18 2013/05/31 12:40:29 wiz Exp $

DISTNAME=	Make-1.00
PKGNAME=	p5-Make-1.00
PKGREVISION=	7
SVR4_PKGNAME=	p5mak
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Make/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
