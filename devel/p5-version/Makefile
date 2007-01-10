# $NetBSD: Makefile,v 1.4 2007/01/10 22:08:05 bad Exp $
#

DISTNAME=	version-0.68
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
