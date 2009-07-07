# $NetBSD: Makefile,v 1.4 2009/07/07 15:42:13 sno Exp $
#

DISTNAME=		asterisk-perl-1.01
PKGNAME=		p5-Asterisk-1.01
CATEGORIES=		comms perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JA/JAMESGOL/}
MASTER_SITES+=		http://asterisk.gnuinter.net/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://asterisk.gnuinter.net/
COMMENT=		Collection of perl modules to be used with Asterisk
LICENSE=		artistic

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/asterisk-perl/.packlist
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Asterisk

EXAMPLE_FILES=		agi-enum.agi agi-sayani.agi agi-test.agi
EXAMPLE_FILES+= 	calleridnamelookup.agi directory.agi manager-test.pl
EXAMPLE_FILES+= 	tts-bofh.agi tts-line.agi tts-ping.agi

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
