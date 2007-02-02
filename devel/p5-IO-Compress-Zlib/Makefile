# $NetBSD: Makefile,v 1.1.1.1 2007/02/02 19:09:57 wiz Exp $

DISTNAME=		IO-Compress-Zlib-2.003
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5icz
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Compress-Zlib/
COMMENT=		Perl module to parse gzip and zip files and buffers

DEPENDS+=		p5-IO-Compress-Base>=2.003:../../devel/p5-IO-Compress-Base
DEPENDS+=		p5-Compress-Raw-Zlib>=2.003:../../devel/p5-Compress-Raw-Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Compress/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
