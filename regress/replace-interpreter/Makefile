# $NetBSD: Makefile,v 1.2 2020/05/09 22:13:30 rillig Exp $
#
# Ensures that replace-interpreter comes before check-portability.
# Without this, it would not be possible to quickly and easily patch
# bash programs that declare /bin/sh as their interpreter.
#

PKGNAME=	replace-interpreter-2020.05.09
CATEGORIES=	pkgtools
DISTFILES=	# none

COMMENT=	Ensures correct order of replace-interpreter
LICENSE=	2-clause-bsd

USE_TOOLS+=	printf chmod bash
WRKSRC=		${WRKDIR}
BUILD_DIRS=	# none
DESCR_SRC=	/dev/null
AUTO_MKDIRS=	yes

REPLACE_BASH=	command

do-extract:
	${RUN} printf '%s\n' '#! /bin/sh' 'test a == b' > ${WRKSRC}/command
	${RUN} chmod +x ${WRKSRC}/command

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/command \
		${DESTDIR}${PREFIX}/bin/regress-replace-interpreter

.include "../../mk/bsd.pkg.mk"
