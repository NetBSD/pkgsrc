# $NetBSD: Makefile,v 1.18 2022/06/28 11:32:16 wiz Exp $

DISTNAME=	Devel-Dumpvar-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Dumpvar
COMMENT=	Perl 5 module providing a pure-OO reimplementation of dumpvar.pl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Devel/Dumpvar/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
