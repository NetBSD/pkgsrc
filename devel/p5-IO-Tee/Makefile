# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:11 obache Exp $
#

DISTNAME=	IO-Tee-0.64
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5ite
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/search?module=IO::Tee
COMMENT=	Multiplex output to multiple output handles

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Tee/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
