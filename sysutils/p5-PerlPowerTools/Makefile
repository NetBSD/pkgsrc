# $NetBSD: Makefile,v 1.1 2025/11/17 04:44:45 scole Exp $

DISTNAME=	PerlPowerTools-1.053
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_GITHUB:=briandfoy/}
GITHUB_PROJECT=	PerlPowerTools
GITHUB_RELEASE=	release-1.053

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/PerlPowerTools
COMMENT=	BSD utilities written in pure Perl
LICENSE=	(${PERL5_LICENSE}) AND 2-clause-bsd AND artistic-2.0 AND gnu-gpl-v2

USE_LANGUAGES=	# none
USE_TOOLS+=	cp gmake ls perl

SUBST_CLASSES+=		moreperl
SUBST_STAGE.moreperl=	post-extract
SUBST_MESSAGE.moreperl=	Fixing perl paths
SUBST_FILES.moreperl=	bin/nl
SUBST_SED.moreperl=	-e 1s,/usr/bin/env.perl,${PERL5:Q},

DEPENDS+=	p5-App-a2p-[0-9]*:../../devel/p5-App-a2p
DEPENDS+=	p5-App-find2perl-[0-9]*:../../devel/p5-App-find2perl
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

TEST_DEPENDS+=	p5-IPC-Run3-[0-9]*:../../devel/p5-IPC-Run3
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

# xxx install in a separate directory.  may be a simpler way to do.
# if installing to default location, makefile (& plist) can be much
# simplified, but trying avoid path and name conflicts with system
# utilities and other packages

# xxx "file" command not working, needs path to magic and file format
# changed.  probably other commands should be checked out a bit more

PPT_DNAME=		p5-PerlPowerTools
PLIST_SUBST+=		PPT_DNAME="${PPT_DNAME}"

GENERATE_PLIST+=	( cd ${DESTDIR}${PREFIX} && ${LS} \
			${PPT_DNAME}/lib/perl5/*/auto/PerlPowerTools/.packlist \
			${PPT_DNAME}/lib/perl5/*/perllocal.pod );

do-configure:
	cd ${WRKSRC} && ${PERL5} Makefile.PL \
		INSTALL_BASE=${DESTDIR}${PREFIX}/${PPT_DNAME}

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	cd ${WRKSRC} && ${GMAKE} install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
