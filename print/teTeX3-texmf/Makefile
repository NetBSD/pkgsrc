# $NetBSD: Makefile,v 1.4 2005/05/16 03:04:45 jlam Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGREVISION=	1
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

CONFLICTS+=	teTeX-share-[0-9]*

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_GNU_TOOLS+=	patch

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if !empty(EXTRACT_USING:Mgtar)
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${GTAR} -X ${FILESDIR}/exclude -xpf -
.else
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -O -cr `${CAT} ${FILESDIR}/exclude`
.endif
	cd ${PREFIX}/share/texmf/dvipdfm/config && \
	${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${FILESDIR}/dvipdfm-config.diff && \
	${RM} config.orig

.include "../../mk/bsd.pkg.mk"
