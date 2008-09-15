# $NetBSD: Makefile,v 1.2 2008/09/15 12:27:45 he Exp $

DISTNAME=	POE-Test-Loops-1.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/POE-Test-Loops/
COMMENT=	Perl module providing reusable tests for POE::Loop authors

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/POE/Test/Loops/.packlist

TESTS_TO_FIX= comp_tcp_concurrent.pm all_errors.pm comp_tcp.pm \
	connect_errors.pm k_alarms.pm k_aliases.pm k_detach.pm \
	k_selects.pm k_sig_child.pm k_signals.pm sbk_signal_init.pm \
	ses_nfa.pm ses_session.pm wheel_accept.pm wheel_curses.pm \
	wheel_readline.pm wheel_readwrite.pm wheel_run.pm wheel_sf_ipv6.pm \
	wheel_sf_tcp.pm wheel_sf_udp.pm wheel_sf_unix.pm wheel_tail.pm

.for t in ${TESTS_TO_FIX}
REPLACE_PERL+= lib/POE/Test/Loops/${t}
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
