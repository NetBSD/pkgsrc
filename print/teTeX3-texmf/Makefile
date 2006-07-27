# $NetBSD: Makefile,v 1.14 2006/07/27 00:09:06 hubertf Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGREVISION=	4
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kei@NetBSD.org,pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

CONFLICTS+=	teTeX-share-[0-9]*

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	patch

EXTRACT_OPTS=		-X ${FILESDIR}/exclude
EXTRACT_OPTS_TAR=	-p

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf-dist
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${PREFIX}/share/texmf-dist; ${EXTRACT_CMD}
	cd ${PREFIX}/share/texmf-dist/dvipdfm/config && \
	${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${FILESDIR}/dvipdfm-config.diff && \
	${RM} config.orig

.include "../../mk/bsd.pkg.mk"
