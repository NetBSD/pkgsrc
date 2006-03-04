# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:22 jlam Exp $

DISTNAME=	Make-1.00
PKGNAME=	p5-Make-1.00
SVR4_PKGNAME=	p5mak
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Make/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
