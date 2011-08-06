# $NetBSD: Makefile,v 1.10 2011/08/06 13:15:54 adam Exp $

DISTNAME=	POE-Test-Loops-1.312
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Test-Loops/
COMMENT=	Perl module providing reusable tests for POE::Loop authors
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Test/Loops/.packlist

TESTS_TO_FIX= 00_info.pm comp_tcp_concurrent.pm all_errors.pm comp_tcp.pm \
	connect_errors.pm k_alarms.pm k_aliases.pm k_detach.pm \
	k_run_returns.pm k_selects.pm k_sig_child.pm k_signals.pm \
	k_signals_rerun.pm sbk_signal_init.pm \
	ses_nfa.pm ses_session.pm wheel_accept.pm wheel_curses.pm \
	wheel_readline.pm wheel_readwrite.pm wheel_run.pm wheel_sf_ipv6.pm \
	wheel_sf_tcp.pm wheel_sf_udp.pm wheel_sf_unix.pm wheel_tail.pm \
	z_kogman_sig_order.pm \
	z_leolo_wheel_run.pm z_merijn_sigchld_system.pm z_rt39872_sigchld.pm \
	z_rt39872_sigchld_stop.pm z_rt53302_fh_watchers.pm \
	z_rt54319_bazerka_followtail.pm z_steinert_signal_integrity.pm

.for t in ${TESTS_TO_FIX}
REPLACE_PERL+= lib/POE/Test/Loops/${t}
.endfor

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-configure
SUBST_FILES.perl=	lib/POE/Test/Loops.pm
SUBST_SED.perl=		-e 's,\#!/usr/bin/perl,\#!${PERL5},g'

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
