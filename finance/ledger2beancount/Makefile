# $NetBSD: Makefile,v 1.2 2020/03/23 16:49:07 riastradh Exp $

DISTNAME=	ledger2beancount-2.0
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=zacchiro/}
GITHUB_PROJECT=	ledger2beancount

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zacchiro/ledger2beancount/
COMMENT=	Script to convert ledger to beancount
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake
USE_TOOLS+=	perl:run

TOOL_DEPENDS+=	scdoc>=0:../../textproc/scdoc

DEPENDS+=	p5-Config-Onion>=0:../../devel/p5-Config-Onion
DEPENDS+=	p5-Date-Calc>=0:../../devel/p5-Date-Calc
DEPENDS+=	p5-DateTime-Format-Strptime>=1.58:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-File-BaseDir>=0:../../devel/p5-File-BaseDir
DEPENDS+=	p5-Getopt-Long-Descriptive>=0:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-String-Interpolate>=0:../../textproc/p5-String-Interpolate

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

USE_TOOLS+=	gsed:test

TEST_ENV+=	SORT=gsort

TEST_TARGET=	test

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
