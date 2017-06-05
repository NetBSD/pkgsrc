# $NetBSD: Makefile,v 1.17 2017/06/05 14:22:19 ryoon Exp $
#

DISTNAME=		asterisk-perl-1.03
PKGNAME=		p5-Asterisk-1.03
PKGREVISION=		7
CATEGORIES=		comms perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JA/JAMESGOL/}
MASTER_SITES+=		http://asterisk.gnuinter.net/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://asterisk.gnuinter.net/
COMMENT=		Collection of perl modules to be used with Asterisk
LICENSE=		artistic

PERL5_PACKLIST=		auto/asterisk-perl/.packlist
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Asterisk

EXAMPLE_FILES=		agi-enum.agi agi-sayani.agi agi-test.agi
EXAMPLE_FILES+= 	calleridnamelookup.agi directory.agi manager-test.pl
EXAMPLE_FILES+= 	tts-bofh.agi tts-line.agi tts-ping.agi

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
