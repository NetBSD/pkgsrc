# $NetBSD: Makefile,v 1.13 2008/06/12 02:14:39 joerg Exp $

DISTNAME=		Net-IRC-0.75
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5nir
PKGREVISION=		2
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://theoryx5.uwinnipeg.ca/CPAN/data/Net-IRC/
COMMENT=		Perl Internet Relay Chat (IRC) module

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Net/IRC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
