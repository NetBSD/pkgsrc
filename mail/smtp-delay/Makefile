# $NetBSD: Makefile,v 1.2 2024/10/11 06:48:04 nia Exp $

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

LDFLAGS.SunOS+=		-lsocket -lnsl

do-build:
	cd ${WRKSRC};	\
	${CC} ${CFLAGS} ${LDFLAGS} -o ${PKGBASE} ${PKGBASE}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
