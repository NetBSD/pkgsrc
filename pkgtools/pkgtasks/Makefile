# $NetBSD: Makefile,v 1.3 2017/06/01 23:38:29 wiz Exp $

DISTNAME=		pkgtasks-1-1.9
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		https://github.com/ultijlam/pkgtasks
COMMENT=		Package tasks
LICENSE=		2-clause-bsd

TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		sh

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		POSIX_SHELL=${TOOLS_SH:Q}
MAKE_JOBS_SAFE=		no

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
