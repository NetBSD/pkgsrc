# $NetBSD: Makefile,v 1.23 2007/11/30 15:32:17 wiz Exp $

DISTNAME=		Compress-Zlib-2.008
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://search.cpan.org/dist/Compress-Zlib/
COMMENT=		Perl5 module interface to the zlib compression library

DEPENDS+=		p5-Compress-Raw-Zlib>=2.008:../../devel/p5-Compress-Raw-Zlib
DEPENDS+=		p5-IO-Compress-Zlib>=2.008:../../devel/p5-IO-Compress-Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Compress/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
