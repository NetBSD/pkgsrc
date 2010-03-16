# $NetBSD: Makefile,v 1.5 2010/03/16 23:46:40 sno Exp $
#

DISTNAME=	IO-Prompt-0.997
PKGNAME=	p5-${DISTNAME:S/997/99.7/}
#PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCONWAY/}

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
