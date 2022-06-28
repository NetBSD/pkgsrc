# $NetBSD: Makefile,v 1.27 2022/06/28 11:34:59 wiz Exp $

DISTNAME=		dnstracer-1.10
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		https://www.mavetju.org/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.mavetju.org/unix/general.php
COMMENT=		Tool to trace dns queries
LICENSE=		2-clause-bsd

USE_PKGLOCALEDIR=	yes
USE_FEATURES+=		inet6
WRKSRC=			${WRKDIR}/${PKGBASE}
AUTO_MKDIRS=		yes
USE_TOOLS+=		gzip tar perl:run pod2man

CFLAGS.SunOS+=		-Du_int16_t=uint16_t -Du_int32_t=uint32_t
LDFLAGS.Darwin+=	-lresolv
LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

# filename is .tar.bz2, but it seems .tar.gz format
do-extract:
	(cd ${WRKDIR}; \
	${TAR} zxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} )

# Makefile has (non DESTDIR type) install: target, but replacing it
do-install:
	(cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dnstracer   ${DESTDIR}${PREFIX}/bin; \
	${INSTALL_DATA}    dnstracer.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8 \
	)

.include "../../mk/bsd.pkg.mk"
