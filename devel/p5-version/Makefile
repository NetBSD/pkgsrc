# $NetBSD: Makefile,v 1.9 2008/10/10 22:07:09 he Exp $
#

DISTNAME=	version-0.76
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=version/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/dist/version/
COMMENT=	Perl extension for Version Objects

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE= Module::Build

REPLACE_PERL+=	lib/version.pm
REPLACE_PERL+=	vutil/lib/version/vxs.pm

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/version/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
