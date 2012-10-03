# $NetBSD: Makefile,v 1.9 2012/10/03 21:55:08 wiz Exp $
#

DISTNAME=	IO-Prompt-0.997001
PKGNAME=	p5-${DISTNAME:S/997001/99.7.001/}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~dconway/IO-Prompt/
COMMENT=	Interactively prompt for user input
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{perl>=5.10,p5-version-[0-9]*}:../../devel/p5-version
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Want-[0-9]*:../../devel/p5-Want

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/IO/Prompt/.packlist

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
