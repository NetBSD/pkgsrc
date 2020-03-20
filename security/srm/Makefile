# $NetBSD: Makefile,v 1.9 2020/03/20 11:58:19 nia Exp $
#

DISTNAME=	srm-1.2.15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=srm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://srm.sourceforge.net/
COMMENT=	Secure replacement for rm(1)
LICENSE=	x11

GNU_CONFIGURE=	yes

CONFLICTS+=	sr-[0-9]* # bin/srm

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ./test.sh

.include "../../mk/bsd.pkg.mk"
