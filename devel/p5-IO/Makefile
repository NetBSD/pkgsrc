# $NetBSD: Makefile,v 1.6 2012/10/03 21:55:07 wiz Exp $
#

DISTNAME=		IO-1.25
PKGNAME=		p5-${DISTNAME}00
PKGREVISION=		3
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
