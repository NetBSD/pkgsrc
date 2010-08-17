# $NetBSD: Makefile,v 1.10 2010/08/17 06:38:04 sno Exp $

DISTNAME=	Config-Any-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Config-Any/
COMMENT=	Perl extension for handling config files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5.10,p5-Module-Pluggable>=3.01}:../../devel/p5-Module-Pluggable

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Config/Any/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
