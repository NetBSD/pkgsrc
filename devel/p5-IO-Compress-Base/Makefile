# $NetBSD: Makefile,v 1.2 2007/03/08 18:59:47 wiz Exp $

DISTNAME=		IO-Compress-Base-2.004
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5icb
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO-Compress-Base/
COMMENT=		Base class for IO::Compress and IO::Uncompress modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Compress/Base/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
