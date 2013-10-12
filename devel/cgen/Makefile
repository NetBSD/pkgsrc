# $NetBSD: Makefile,v 1.1 2013/10/12 08:39:02 ryoon Exp $

DISTNAME=	cgen-20131001
CATEGORIES=	devel
MASTER_SITES=	ftp://sourceware.org/pub/cgen/snapshots/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceware.org/cgen/
COMMENT=	CGEN, the Cpu tools GENerator
LICENSE=	gnu-gpl-v3 # with Red Hat exception

DEPENDS+=	guile-[0-9]*:../../lang/guile

WRKSRC=		${WRKDIR}/src

CONFIGURE_DIRS=	cgen

USE_TOOLS+=	makeinfo pax
USE_LANGUAGES=	c

GNU_CONFIGURE=	yes
INFO_FILES=	yes

BUILD_TARGET=	info
INSTALL_TARGET=	install-info

CGEN_DIR=	share/cgen
INSTALLATION_DIRS+=	${CGEN_DIR}/cgen ${CGEN_DIR}/cpu

post-install:
	cd ${WRKSRC}/${CONFIGURE_DIRS} && \
	${FIND} . -type f \! \( -name '*.orig' -o -name 'Makefile' -o -name 'config*' \) -print | \
		pax -rw ${DESTDIR}${PREFIX}/${CGEN_DIR}/cgen
	cd ${WRKSRC}/cpu && \
	${FIND} . -type f \! \( -name '*.orig' -o -name 'Makefile*' -o -name 'config*' \) -print | \
		pax -rw ${DESTDIR}${PREFIX}/${CGEN_DIR}/cpu

.include "../../mk/bsd.pkg.mk"
