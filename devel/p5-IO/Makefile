# $NetBSD: Makefile,v 1.3 2009/05/18 06:54:45 sno Exp $
#

DISTNAME=		IO-1.25
PKGNAME=		p5-${DISTNAME}00
SVR4_PKGNAME=		p5io
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IO/
COMMENT=		Perl module for various IO modules

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/IO/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
