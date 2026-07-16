# $NetBSD: Makefile,v 1.3 2026/07/16 19:04:55 wiz Exp $

DISTNAME=	PerlPowerTools-1.053
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=briandfoy/}
GITHUB_PROJECT=	PerlPowerTools
GITHUB_RELEASE=	release-1.053

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/PerlPowerTools
COMMENT=	BSD utilities written in pure Perl
LICENSE=	(${PERL5_LICENSE}) AND 2-clause-bsd AND artistic-2.0 AND gnu-gpl-v2

USE_LANGUAGES=	# none

SUBST_CLASSES+=		moreperl
SUBST_STAGE.moreperl=	post-extract
SUBST_MESSAGE.moreperl=	Fixing perl paths
SUBST_FILES.moreperl=	bin/nl
SUBST_SED.moreperl=	-e 1s,/usr/bin/env.perl,${PERL5:Q},

DEPENDS+=	p5-App-a2p-[0-9]*:../../devel/p5-App-a2p
DEPENDS+=	p5-App-find2perl-[0-9]*:../../devel/p5-App-find2perl
DEPENDS+=	p5-Curses-[0-9]*:../../devel/p5-Curses
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

TEST_DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

# xxx
# file: still broken, need /etc/magic and/or updated format
# units: has some built-in units, fix to grok/usr/share/misc/units.lib ?

PPT_DNAME=		p5-PerlPowerTools
PLIST_SUBST+=		PPT_DNAME="${PPT_DNAME}"

INSTALLATION_DIRS+=	${PREFIX}/${PPT_DNAME}/bin \
			${PREFIX}/${PPT_DNAME}/man/man1 \
			${PERL5_INSTALLVENDORMAN3DIR}

# install utilities and related man pages in separate directory
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/blib/script/* ${DESTDIR}${PREFIX}/${PPT_DNAME}/bin
	${INSTALL_MAN} ${WRKSRC}/blib/man1/* ${DESTDIR}${PREFIX}/${PPT_DNAME}/man/man1
	${INSTALL_MAN} ${WRKSRC}/blib/man3/* ${DESTDIR}/${PERL5_INSTALLVENDORMAN3DIR}
	${INSTALL_LIB_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_LIB_DIR} ${DESTDIR}${PERL5_INSTALLVENDORLIB}/PerlPowerTools
	${INSTALL_DATA} ${WRKSRC}/blib/lib/PerlPowerTools.pm ${WRKSRC}/blib/lib/ppt.pm \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}
	${INSTALL_DATA} ${WRKSRC}/blib/lib/PerlPowerTools/SymbolicMode.pm \
		${DESTDIR}${PERL5_INSTALLVENDORLIB}/PerlPowerTools

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
