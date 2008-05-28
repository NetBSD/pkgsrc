# $NetBSD: Makefile,v 1.24 2008/05/28 22:12:08 abs Exp $

DISTNAME=		Compress-Zlib-2.011
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5czl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Compress/}

MAINTAINER=		damon@brodiefamily.org
HOMEPAGE=		http://search.cpan.org/dist/Compress-Zlib/
COMMENT=		Perl5 module interface to the zlib compression library

DEPENDS+=		p5-Compress-Raw-Zlib>=2.008:../../devel/p5-Compress-Raw-Zlib
DEPENDS+=		p5-IO-Compress-Zlib>=2.008:../../devel/p5-IO-Compress-Zlib

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Compress/Zlib/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
