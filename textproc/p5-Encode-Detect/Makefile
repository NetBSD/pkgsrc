# $NetBSD: Makefile,v 1.11 2013/12/09 14:17:53 obache Exp $
#

DISTNAME=		Encode-Detect-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Encode-Detect/
COMMENT=		Perl module that detects the encoding of data
LICENSE=		mpl-1.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=		{perl>=5.9.3,p5-ExtUtils-CBuilder-[0-9]*}:../../devel/p5-ExtUtils-CBuilder

USE_LANGUAGES+=		c c++

PERL5_PACKLIST=		auto/Encode/Detect/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
