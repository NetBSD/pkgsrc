# $NetBSD: Makefile,v 1.1.1.1 2003/02/23 04:59:31 kei Exp $

DISTNAME=	tetex-texmf-2.0.1
PKGNAME=	teTeX2-share-2.0.1
PKGREVISION=	# empty
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX, version 2

CONFLICTS+=	teTeX-share-[0-9]*

DIST_SUBDIR=	teTeX
WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	yes
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
NO_MTREE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
.if defined(EXTRACT_USING_PAX)
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${PAX} -cr `${CAT} ${FILESDIR}/exclude`
.else
	cd ${PREFIX}/share/texmf; ${DECOMPRESS_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${GTAR} -X ${FILESDIR}/exclude -xpf -
.endif

.include "../../mk/bsd.pkg.mk"
