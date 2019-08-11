# $NetBSD: Makefile,v 1.20 2019/08/11 13:23:28 wiz Exp $
#

DISTNAME=		Encode-Detect-1.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Encode/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Encode-Detect
COMMENT=		Perl module that detects the encoding of data
LICENSE=		mpl-1.1

#BUILD_DEPENDS+=		{perl>=5.9.3,p5-ExtUtils-CBuilder-[0-9]*}:../../devel/p5-ExtUtils-CBuilder

USE_LANGUAGES+=		c c++

PERL5_PACKLIST=		auto/Encode/Detect/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
