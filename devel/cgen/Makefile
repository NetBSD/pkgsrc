# $NetBSD: Makefile,v 1.4 2026/10/14 15:02:46 ryoon Exp $

DISTNAME=	cgen-20260101
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://sourceware.org/cgen/
COMMENT=	CGEN, the Cpu tools GENerator
LICENSE=	gnu-gpl-v3 # with Red Hat exception

DEPENDS+=	guile30-[0-9]*:../../lang/guile30

USE_TOOLS+=	automake makeinfo pax
USE_LANGUAGES=	c

GNU_CONFIGURE=	yes
INFO_FILES=	yes

BUILD_TARGET=	info
INSTALL_TARGET=	install-info

CGEN_DIR=		share/cgen
INSTALLATION_DIRS+=	${CGEN_DIR}

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fi

post-install:
	${RM} -rf ${WRKSRC}/autom4te.cache
	cd ${WRKSRC} && \
	${FIND} . -type f \! \( -name '*.orig' -o -name 'Makefile' -o -name 'config*' \) -print | \
		pax -rw ${DESTDIR}${PREFIX}/${CGEN_DIR}

.include "../../mk/bsd.pkg.mk"
