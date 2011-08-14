# $NetBSD: Makefile,v 1.15 2011/08/14 12:26:16 obache Exp $

DISTNAME=	Make-1.00
PKGNAME=	p5-Make-1.00
PKGREVISION=	5
SVR4_PKGNAME=	p5mak
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Make/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ni-s.u-net.com/
COMMENT=	Perl5 module implementing 'make' in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Make/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
