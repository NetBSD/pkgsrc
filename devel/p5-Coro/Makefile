# $NetBSD: Makefile,v 1.32 2022/06/28 11:32:08 wiz Exp $

DISTNAME=	Coro-6.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Coro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Coro
COMMENT=	Perl module for threads
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability
DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense
DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent

PERL5_PACKLIST=	auto/Coro/.packlist
REPLACE_PERL+=	Coro/jit-amd64-unix.pl Coro/jit-x86-unix.pl

MAKE_ENV.NetBSD+=	CORO_JIT=n

.include "../../devel/p5-EV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
