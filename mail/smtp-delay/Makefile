# $NetBSD: Makefile,v 1.1 2023/12/05 17:36:16 schmonz Exp $

DISTNAME=		smtp-delay
PKGNAME=		${DISTNAME}-0.20
CATEGORIES=		mail
MASTER_SITES=		https://www.lewis.org/~jlewis/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.c

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.lewis.org/~jlewis/smtp-delay/
COMMENT=		Introduce SMTP banner delays for qmail
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC};	\
	${CC} ${CFLAGS} ${LDFLAGS} -o ${PKGBASE} ${PKGBASE}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
