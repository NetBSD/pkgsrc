# $NetBSD: Makefile,v 1.22 2022/06/28 11:33:02 wiz Exp $

DISTNAME=	Parallel-Prefork-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parallel-Prefork
COMMENT=	Perl 5 simple prefork server framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Lite>=0.04:../../devel/p5-Class-Accessor-Lite
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Proc-Wait3>=0.03:../../devel/p5-Proc-Wait3
DEPENDS+=	p5-Scope-Guard-[0-9]*:../../devel/p5-Scope-Guard
DEPENDS+=	p5-Signal-Mask-[0-9]*:../../devel/p5-Signal-Mask

# for make test
BUILD_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork
BUILD_DEPENDS+=	p5-forks-[0-9]*:../../devel/p5-forks
BUILD_DEPENDS+=	p5-IPC-Signal-[0-9]*:../../devel/p5-IPC-Signal

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Parallel/Prefork/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
