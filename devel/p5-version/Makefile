# $NetBSD: Makefile,v 1.12 2009/09/12 21:18:51 sno Exp $
#

DISTNAME=	version-0.7702
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=version/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/version/
COMMENT=	Perl extension for Version Objects
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews
# would require Module::Build >= 0.3305 - but this will result in circular dependency
PERL5_MODULE_TYPE= Module::Build

REPLACE_PERL+=	lib/version.pm
REPLACE_PERL+=	vutil/lib/version/vxs.pm

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/version/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
