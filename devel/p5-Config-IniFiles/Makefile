# $NetBSD: Makefile,v 1.40 2015/04/21 00:06:13 mef Exp $

DISTNAME=	Config-IniFiles-2.86
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-IniFiles/
COMMENT=	Perl module for reading .ini-style configuration files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-List-MoreUtils>=0.33:../../devel/p5-List-MoreUtils

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Config/IniFiles/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
