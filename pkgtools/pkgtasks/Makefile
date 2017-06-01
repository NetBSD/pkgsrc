# $NetBSD: Makefile,v 1.1 2017/06/01 01:58:34 jlam Exp $

DISTNAME=		pkgtasks-1-1.9
CATEGORIES=		pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		jlam@NetBSD.org
COMMENT=		Package tasks
LICENSE=		2-clause-bsd

TEST_TARGET=		check
USE_LANGUAGES=		# empty
USE_TOOLS=		sh

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		POSIX_SHELL=${TOOLS_SH:Q}

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
