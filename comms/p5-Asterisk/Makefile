# $NetBSD: Makefile,v 1.2 2008/08/05 21:42:39 he Exp $
#

DISTNAME=		asterisk-perl-0.10
PKGNAME=		p5-Asterisk-0.10
CATEGORIES=		comms perl5
MASTER_SITES=		http://asterisk.gnuinter.net/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://asterisk.gnuinter.net/
COMMENT=		Collection of perl modules to be used with Asterisk

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/asterisk-perl/.packlist
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Asterisk

EXAMPLE_FILES=		agi-enum.agi calleridnamelookup.agi tts-line.agi
EXAMPLE_FILES+=		agi-sayani.agi manager-test.pl tts-ping.agi
EXAMPLE_FILES+=		agi-test.agi tts-bofh.agi

.for file in ${EXAMPLE_FILES}
REPLACE_PERL+=		${WRKSRC}/examples/${file}
.endfor

post-install:
	${INSTALL_SCRIPT_DIR} ${EXAMPLES_DIR}
.for file in ${EXAMPLE_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/${file} ${EXAMPLES_DIR}
.endfor

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
