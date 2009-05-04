# $NetBSD: Makefile,v 1.3 2009/05/04 05:57:14 sno Exp $

DISTNAME=		IO-Compress-2.018
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5icb
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Compress/
COMMENT=		IO Interface to compressed data files/buffers
LICENSE=		gnu-gpl-v2 # OR artistic

CONFLICTS+=		p5-IO-Compress-Base-[0-9]*
CONFLICTS+=		p5-IO-Compress-Zlib-[0-9]*
CONFLICTS+=		p5-IO-Compress-Bzip2-[0-9]*
CONFLICTS+=		p5-Compress-Zlib-[0-9]*

DEPENDS+=		p5-Compress-Raw-Zlib>=2.018:../../devel/p5-Compress-Raw-Zlib
DEPENDS+=		p5-Compress-Raw-Bzip2>=2.018:../../devel/p5-Compress-Raw-Bzip2

SUPERSEDES=		p5-IO-Compress-Base<2.017
SUPERSEDES+=		p5-IO-Compress-Bzip2<2.017
SUPERSEDES+=		p5-IO-Compress-Zlib<2.017

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Compress/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
