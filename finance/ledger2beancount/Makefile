# $NetBSD: Makefile,v 1.6 2020/11/18 22:39:15 riastradh Exp $

DISTNAME=	ledger2beancount-2.5
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=beancount/}
GITHUB_PROJECT=	ledger2beancount

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/beancount/ledger2beancount/
COMMENT=	Script to convert ledger to beancount
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_TOOLS+=	perl:run

TOOL_DEPENDS+=	scdoc>=0:../../textproc/scdoc

DEPENDS+=	p5-Date-Calc>=0:../../devel/p5-Date-Calc
DEPENDS+=	p5-DateTime-Format-Strptime>=1.58:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-File-BaseDir>=0:../../devel/p5-File-BaseDir
DEPENDS+=	p5-Getopt-Long-Descriptive>=0:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Regexp-Common>=0:../../textproc/p5-Regexp-Common
DEPENDS+=	p5-String-Interpolate>=0:../../textproc/p5-String-Interpolate
DEPENDS+=	p5-YAML-XS>=0:../../textproc/p5-YAML-XS
DEPENDS+=	p5-enum>=0:../../devel/p5-enum

REPLACE_PERL+=	bin/ledger2beancount

BUILD_TARGET=	man

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGMANDIR}/man5

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ledger2beancount ${DESTDIR}${PREFIX}/bin/.
	${INSTALL_MAN} ${WRKSRC}/docs/ledger2beancount.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/.
	${INSTALL_MAN} ${WRKSRC}/docs/ledger2beancount.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/.

TEST_DEPENDS+=	coreutils>=0:../../sysutils/coreutils
TEST_DEPENDS+=	ledger>=3.0.0:../../finance/ledger
TEST_DEPENDS+=	${PYPKGPREFIX}-beancount>=0:../../finance/py-beancount
TEST_DEPENDS+=	p5-YAML-Syck>=0:../../textproc/p5-YAML-Syck

# runtests.sh relies on `\s', a GNUism meaning `[[:space:]]', in sed,
# so use gsed.  This should be gsed:test, but that triggers a bug in
# the mk/ infrastructure -- the checksum logic thinks TOOL_SED is gsed,
# but the depends logic hasn't actually brought gsed in because it's
# only needed for test.
USE_TOOLS+=	gsed

# runtests.sh relies on GNU sort's `sort -V' for sorting versions.
TEST_ENV+=	SORT=gsort

TEST_TARGET=	test

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"

# XXX Need to override default pkgsrc settings of these environment
# variables for tests, which require a UTF-8 locale.
TEST_ENV+=	LANG=en_US.UTF-8 LC_CTYPE=en_US.UTF-8 LC_ALL=
