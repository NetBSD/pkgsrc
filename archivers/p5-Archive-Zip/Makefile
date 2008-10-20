# $NetBSD: Makefile,v 1.26 2008/10/20 21:50:50 he Exp $

DISTNAME=		Archive-Zip-1.26
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5zip
CATEGORIES=		archivers perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Archive-Zip/
COMMENT=		Perl5 module interface to manipulate zip files

DEPENDS+=		p5-Compress-Zlib>=1.14:../../devel/p5-Compress-Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Archive/Zip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
