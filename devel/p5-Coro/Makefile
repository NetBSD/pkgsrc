# $NetBSD: Makefile,v 1.28 2020/09/06 21:54:32 wiz Exp $

DISTNAME=	Coro-6.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Coro/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Coro
COMMENT=	Perl module for threads
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Canary-Stability-[0-9]*:../../devel/p5-Canary-Stability
DEPENDS+=	p5-common-sense-[0-9]*:../../devel/p5-common-sense
DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent

MAKE_JOBS_SAFE=	no
PERL5_PACKLIST=	auto/Coro/.packlist
REPLACE_PERL+=	Coro/jit-amd64-unix.pl Coro/jit-x86-unix.pl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	CORO_JIT=n
.endif

# test failures on NetBSD as of 6.57:
# t/00_basic.t .... Failed 3/5 subtests
# t/01_unblock.t .. Failed 8/12 subtests
#
# Test Summary Report
# -------------------
# t/00_basic.t  (Wstat: 139 Tests: 2 Failed: 0)
#   Non-zero wait status: 139
#   Parse errors: Bad plan.  You planned 5 tests but ran 2.
# t/01_unblock.t (Wstat: 139 Tests: 4 Failed: 0)
#   Non-zero wait status: 139
#   Parse errors: Bad plan.  You planned 12 tests but ran 4.
# Files=2, Tests=6,  1 wallclock secs ( 0.00 usr  0.02 sys +  0.04 cusr  0.04 csys =  0.10 CPU)
# Result: FAIL
# Failed 2/2 test programs. 0/6 subtests failed.

.include "../../devel/p5-EV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
