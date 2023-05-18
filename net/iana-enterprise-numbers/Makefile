# $NetBSD: Makefile,v 1.1 2023/05/18 08:10:26 spz Exp $
#
# Please also update the dependency pattern in mozilla-rootcerts-openssl
# and bump its version when updating this package.

DISTNAME=	enterprise-numbers-${PEN_DATE}
CATEGORIES=	net
MASTER_SITES=	-https://www.iana.org/assignments/enterprise-numbers.txt
EXTRACT_SUFX=	# empty
DISTFILES=	${PEN}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.iana.org/assignments/enterprise-numbers/
COMMENT=	IANA Private Enterprise Numbers (PENs)
LICENSE=	cc0-1.0-universal

PEN_DATE=	20230518
PEN=		enterprise-numbers-${PEN_DATE}.txt

WRKSRC=		${WRKDIR}
DATADIR=	${PREFIX}/share/misc

INSTALLATION_DIRS=	${DATADIR}

do-extract:
	${CP} ${DISTDIR}/${PEN} ${WRKSRC}/${PEN}

do-build:
	:

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PEN} ${DESTDIR}${DATADIR}/enterprise-numbers

.include "../../mk/bsd.pkg.mk"
