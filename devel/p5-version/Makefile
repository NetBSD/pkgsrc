# $NetBSD: Makefile,v 1.8 2008/07/17 09:45:15 rhaen Exp $
#

DISTNAME=	version-0.7501
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPEACOCK/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~jpeacock/version/
COMMENT=	Perl extension for Version Objects

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/version/vxs/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
