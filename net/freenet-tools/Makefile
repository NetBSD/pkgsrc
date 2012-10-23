# $NetBSD: Makefile,v 1.14 2012/10/23 17:18:21 asau Exp $
#

DISTNAME=		ft-0.2.25
PKGNAME=		${DISTNAME:S/ft-/freenet-tools-/}
WRKSRC=			${WRKDIR}/ft
CATEGORIES=		net www
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Freenet Tools, freesite manipulation tools for Freenet and Entropy

USE_TOOLS+=		gmake

MAKE_FLAGS+=		CC=${CC:Q} LD=${CC:Q} CFLAGS=${CFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q}
CFLAGS+=		-DFT_BIN=\"${PREFIX}/bin\" -D_DEBUG

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ft ${DESTDIR}${PREFIX}/bin/ft
.for f in fcpbroadcast fcpchk fcpget fcpgetsite fcphello fcpinv fcpkey \
	  fcpput fcpputsite fcpreceive
	${LN} -s -f ft ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
