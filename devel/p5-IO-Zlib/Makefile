# $NetBSD: Makefile,v 1.13 2006/11/05 17:49:34 joerg Exp $

DISTNAME=		IO-Zlib-1.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5izl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Zlib/
COMMENT=		Perl5 IO:: style interface to Compress::Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Compress-Zlib>=1.16:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=		auto/IO/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
