# $NetBSD: Makefile,v 1.23 2025/02/02 13:05:32 pho Exp $

DISTNAME=	hledger-1.41
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command-line interface for the hledger accounting system
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	share/bash-completion/completions
post-install:
	${INSTALL_DATA} ${WRKSRC}/shell-completion/hledger-completion.bash \
		${DESTDIR}${PREFIX}/share/bash-completion/completions/hledger

do-test:
	${RUN}${PKGSRC_SETENV} \
		LD_LIBRARY_PATH=${WRKSRC:Q}/dist/build \
		DYLD_LIBRARY_PATH=${WRKSRC:Q}/dist/build \
		${WRKSRC:Q}/dist/build/hledger/hledger test

# lib:hledger
.include "../../finance/hs-Decimal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-githash/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../finance/hledger-lib/buildlink3.mk"
.include "../../textproc/hs-lucid/buildlink3.mk"
.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-microlens/buildlink3.mk"
.include "../../net/hs-modern-uri/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-tabular/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../textproc/hs-text-ansi/buildlink3.mk"
.include "../../devel/hs-timeit/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.include "../../devel/hs-wizards/buildlink3.mk"

# exe:hledger
.include "../../finance/hs-Decimal/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-githash/buildlink3.mk"
.include "../../finance/hledger-lib/buildlink3.mk"
.include "../../math/hs-math-functions/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-microlens/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-safe/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-tabular/buildlink3.mk"
.include "../../devel/hs-tasty/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../textproc/hs-text-ansi/buildlink3.mk"
.include "../../devel/hs-timeit/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.include "../../devel/hs-utility-ht/buildlink3.mk"
.include "../../devel/hs-wizards/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
