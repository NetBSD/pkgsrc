# $NetBSD: Makefile,v 1.1 2024/02/19 20:50:43 schmonz Exp $

DISTNAME=		sharness-v1.2.0
PKGNAME=		${DISTNAME:S/-v/-/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=felipec/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://felipec.github.io/sharness/
COMMENT=		Shell library to test your tools like Git does
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none
USE_TOOLS+=		gmake perl
NO_BUILD=		yes
REPLACE_SH=		sharness.sh tools/aggregate-results.sh
REPLACE_SH+=		test/sharness.sh test/aggregate-results.sh
REPLACE_SH+=		lib-sharness/functions.sh

TEST_DIRS=		test
TEST_TARGET=		all

TEST_DEPENDS+=		p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty

.include "../../mk/bsd.pkg.mk"
