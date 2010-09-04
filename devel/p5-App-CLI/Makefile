# $NetBSD: Makefile,v 1.7 2010/09/04 11:50:36 sno Exp $
#

DISTNAME=	App-CLI-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-CLI/
COMMENT=	Dispatcher module for command line interface programs
#LICENSE=	artistic OR gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/App/CLI/.packlist

#IC5.8.8DEPENDS+=       p5-Getopt-Long>=2.35:../../devel/p5-Getopt-Long
DEPENDS+=	{perl>=5.10.0,p5-Locale-Maketext-Simple>=0.16}:../../misc/p5-Locale-Maketext-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
