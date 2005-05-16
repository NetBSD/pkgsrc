# $NetBSD: Makefile,v 1.27 2005/05/16 01:15:33 jlam Exp $
#

DISTNAME=	tetex-texmf-2.0.2
PKGNAME=	teTeX-share-2.0.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	listings${EXTRACT_SUFX}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX, version 2

SITES_listings.tar.gz= ${LOCAL_PORTS}

CONFLICTS+=	teTeX2-share-[0-9]*

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_GNU_TOOLS+=		patch
.if !defined(EXTRACT_USING_PAX)
PKGSRC_USE_TOOLS+=	gtar
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if defined(EXTRACT_USING_PAX)
	for i in ${DISTFILES}; do \
		cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/$$i | ${PAX} -O -cr `${CAT} ${FILESDIR}/exclude`; \
	done
.else
	for i in ${DISTFILES}; do \
		cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/$$i | ${GTAR} -X ${FILESDIR}/exclude -xpf -; \
	done
.endif
	cd ${PREFIX}/share/texmf/dvipdfm/config && \
	${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${FILESDIR}/dvipdfm-config.diff && \
	${RM} config.orig

.include "../../mk/bsd.pkg.mk"
