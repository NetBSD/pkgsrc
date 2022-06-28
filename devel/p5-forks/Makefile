# $NetBSD: Makefile,v 1.10 2022/06/28 11:33:39 wiz Exp $

DISTNAME=	forks-0.36
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RY/RYBSKEJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/forks
COMMENT=	Drop-in replacement for Perl threads using fork()
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Acme-Damn-[0-9]*:../../devel/p5-Acme-Damn
DEPENDS+=	p5-List-MoreUtils>=0.15:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Devel-Symdump-[0-9]*:../../devel/p5-Devel-Symdump
DEPENDS+=	p5-Sys-SigAction-[0-9]*:../../sysutils/p5-Sys-SigAction

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/forks/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
