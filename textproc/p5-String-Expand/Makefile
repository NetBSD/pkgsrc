# $NetBSD: Makefile,v 1.9 2021/05/24 19:54:37 wiz Exp $

DISTNAME=	String-Expand-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/String::Expand
COMMENT=	Functions to expand variables in self-referential sets
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Test-More-Behaviour-[0-9]*:../../devel/p5-Test-More-Behaviour
DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/String/Expand/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
