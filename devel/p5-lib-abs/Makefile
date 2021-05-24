# $NetBSD: Makefile,v 1.21 2021/05/24 19:51:59 wiz Exp $
#

DISTNAME=	lib-abs-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=lib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/lib-abs
COMMENT=	Perl 5 module to add in @INC absolute paths from relative ones
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/lib/abs/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled # to handle auto_install flags properly

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
