# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:07 obache Exp $

DISTNAME=		Getopt-Long-2.38
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JV/JV/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~rsavage/Getopt-Simple/
COMMENT=		Extended processing of command line options
LICENSE=		artistic-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Getopt/Long/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
