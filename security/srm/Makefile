# $NetBSD: Makefile,v 1.11 2026/06/20 10:22:15 nia Exp $
#

DISTNAME=	srm-1.2.15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=srm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://srm.sourceforge.net/
COMMENT=	Secure replacement for rm(1)
LICENSE=	x11

GNU_CONFIGURE=	yes

CONFLICTS+=	sr-[0-9]* # bin/srm

# doesn't include <alloca.h> which is needed on SunOS,
# just define the function to the compiler builtin to avoid
# needing a patch.
CFLAGS.SunOS+=	-Dalloca=__builtin_alloca

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./test.sh

.include "../../mk/bsd.pkg.mk"
