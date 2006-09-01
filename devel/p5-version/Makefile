# $NetBSD: Makefile,v 1.3 2006/09/01 14:21:46 abs Exp $
#

DISTNAME=	version-0.6701
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPEACOCK/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~jpeacock/version/
COMMENT=	Perl extension for Version Objects

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/version/vxs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
