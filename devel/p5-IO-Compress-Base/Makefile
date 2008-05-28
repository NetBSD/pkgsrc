# $NetBSD: Makefile,v 1.4 2008/05/28 22:13:22 abs Exp $

DISTNAME=		IO-Compress-Base-2.011
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5icb
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Compress-Base/
COMMENT=		Base class for IO::Compress and IO::Uncompress modules

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IO/Compress/Base/.packlist

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
