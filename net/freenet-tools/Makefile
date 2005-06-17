# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=		ft-0.2.23
PKGNAME=		${DISTNAME:S/ft-/freenet-tools-/}
WRKSRC=			${WRKDIR}/ft
CATEGORIES=		net www
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Freenet Tools, freesite manipulation tools for Freenet and Entropy

USE_TOOLS+=		gmake

MAKE_FLAGS+=		CC=${CC:Q} LD=${CC:Q} CFLAGS=${CFLAGS:Q} LDFLAGS=${LDFLAGS:Q}
CFLAGS+=		-DFT_BIN=\"${PREFIX}/bin\"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ft ${PREFIX}/bin/ft
.for f in fcpchk fcpget fcpgetsite fcphello fcpinv fcpkey fcpput fcpputsite
	${LN} -s -f ft ${PREFIX}/bin/$f
.endfor

.include "../../mk/bsd.pkg.mk"
