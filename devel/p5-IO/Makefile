# $NetBSD: Makefile,v 1.5 2011/08/14 12:26:09 obache Exp $
#

DISTNAME=		IO-1.25
PKGNAME=		p5-${DISTNAME}00
PKGREVISION=		2
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
