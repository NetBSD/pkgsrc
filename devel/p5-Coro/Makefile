# $NetBSD: Makefile,v 1.29 2020/09/19 21:01:28 wiz Exp $

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

# test failures after turning off JIT on NetBSD are random, best run so far:
# as pf 6.57
# t/00_basic.t .......... ok   
# t/01_process.t ........ ok     
# t/02_channel.t ........ ok     
# t/03_channel.t ........ Failed 9/10 subtests 
# t/04_rwlock.t ......... ok     
# t/05_specific.t ....... ok   
# t/06_prio.t ........... Failed 8/10 subtests 
# t/07_eval.t ........... ok   
# t/08_join.t ........... ok     
# t/10_bugs.t ........... ok   
# t/11_deadlock.t ....... ok   
# t/12_exit.t ........... Failed 2/5 subtests 
# t/13_diewarn.t ........ All 7 subtests passed 
# t/14_load.t ........... ok     
# t/15_semaphore.t ...... Failed 6/6 subtests 
# t/16_signal.t ......... ok     
# t/17_rouse.t .......... ok   
# t/18_winder.t ......... ok     
# t/19_handle.t ......... ok   
# t/20_mutual_cancel.t .. ok     
# Test Summary Report
# -------------------
# t/03_channel.t      (Wstat: 139 Tests: 1 Failed: 0)
#   Non-zero wait status: 139
#   Parse errors: Bad plan.  You planned 10 tests but ran 1.
# t/06_prio.t         (Wstat: 139 Tests: 2 Failed: 0)
#   Non-zero wait status: 139
#   Parse errors: Bad plan.  You planned 10 tests but ran 2.
# t/12_exit.t         (Wstat: 0 Tests: 4 Failed: 1)
#   Failed test:  5
#   Parse errors: Tests out of sequence.  Found (5) but expected (4)
#                 Bad plan.  You planned 5 tests but ran 4.
# t/13_diewarn.t      (Wstat: 139 Tests: 7 Failed: 0)
#   Non-zero wait status: 139
# t/15_semaphore.t    (Wstat: 139 Tests: 0 Failed: 0)
#   Non-zero wait status: 139
#   Parse errors: Bad plan.  You planned 6 tests but ran 0.
# Files=20, Tests=182,  0 wallclock secs ( 0.04 usr  0.02 sys +  0.29 cusr  0.07 csys =  0.42 CPU)
# Result: FAIL
# Failed 5/20 test programs. 1/182 subtests failed.

.include "../../devel/p5-EV/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
