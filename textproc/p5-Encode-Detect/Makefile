# $NetBSD: Makefile,v 1.3 2008/09/14 12:46:32 he Exp $
#

DISTNAME=		Encode-Detect-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Encode-Detect/
COMMENT=		Perl module that detects the encoding of data

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_DEPENDS+=		p5-ExtUtils-CBuilder-[0-9]*:../../devel/p5-ExtUtils-CBuilder

USE_LANGUAGES+=		c c++

PERL5_PACKLIST=		auto/Encode/Detect/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
