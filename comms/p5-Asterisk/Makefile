# $NetBSD: Makefile,v 1.25 2022/06/28 11:31:06 wiz Exp $

DISTNAME=		asterisk-perl-1.08
PKGNAME=		p5-Asterisk-${DISTNAME:S/asterisk-perl-//}
PKGREVISION=		5
CATEGORIES=		comms perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IT/ITCHARLIE/}
#MASTER_SITES+=		http://asterisk.gnuinter.net/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://asterisk.gnuinter.net/
COMMENT=		Collection of perl modules to be used with Asterisk
LICENSE=		artistic

DEPENDS+=		p5-Net-Telnet-[0-9]*:../../net/p5-Net-Telnet

PERL5_PACKLIST=		auto/asterisk-perl/.packlist
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Asterisk

EXAMPLE_FILES=		agi-enum.agi agi-sayani.agi agi-test.agi
EXAMPLE_FILES+=		calleridnamelookup.agi directory.agi manager-test.pl
EXAMPLE_FILES+=		tts-bofh.agi tts-line.agi tts-ping.agi

.for file in ${EXAMPLE_FILES}
REPLACE_PERL+=		${WRKSRC}/examples/${file}
.endfor

INSTALLATION_DIRS=	${EXAMPLES_DIR}

post-install:
.for file in ${EXAMPLE_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${file} ${DESTDIR}${EXAMPLES_DIR}
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
