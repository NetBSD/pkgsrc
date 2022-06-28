# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:02 wiz Exp $

DISTNAME=	Server-Starter-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Server/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Server-Starter
COMMENT=	Perl 5 superdaemon for hot-deploying server programs
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Server/Starter/.packlist

BUILD_DEPENDS+=	p5-Test-TCP>=0.11:../../net/p5-Test-TCP
DEPENDS+=	p5-Proc-Wait3-[0-9]*:../../devel/p5-Proc-Wait3
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Scope-Guard-[0-9]*:../../devel/p5-Scope-Guard

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
