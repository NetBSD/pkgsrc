# $NetBSD: Makefile,v 1.10 2006/01/20 23:41:30 jlam Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGREVISION=	2
PKGNAME=	${DISTNAME:C/tetex/teTeX/}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kei@NetBSD.org,hubertf@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX

CONFLICTS+=	teTeX-share-[0-9]*

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	patch

.include "../../mk/bsd.prefs.mk"

.if !empty(EXTRACT_USING:M*tar)
EXTRACT_OPTS_TAR=	-X ${FILESDIR}/exclude -p
.elif !empty(EXTRACT_USING:Mpax)
EXTRACT_OPTS_PAX=	-c `${CAT} ${FILESDIR}/exclude`
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${PREFIX}/share/texmf; ${EXTRACT_CMD${EXTRACT_SUFX}}
	cd ${PREFIX}/share/texmf/dvipdfm/config && \
	${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${FILESDIR}/dvipdfm-config.diff && \
	${RM} config.orig

.include "../../mk/bsd.pkg.mk"
