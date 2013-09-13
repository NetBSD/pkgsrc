# $NetBSD: Makefile,v 1.1 2013/09/13 10:31:29 sno Exp $

DISTNAME=	Unix-Statgrab-0.101
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unix/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Unix-Statgrab/
COMMENT=	Perl extension for collecting information about the machine
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Unix/Statgrab/.packlist
PERL5_MODULE_TYPE=	Module::Build

BUILD_DEPENDS=	p5-Config-AutoConf>=0.19:../../devel/p5-Config-AutoConf

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
