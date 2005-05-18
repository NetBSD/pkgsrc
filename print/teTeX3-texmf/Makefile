# $NetBSD: Makefile,v 1.7 2005/05/18 15:11:13 jlam Exp $
#

DISTNAME=	tetex-texmf-3.0
PKGREVISION=	1
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
USE_GNU_TOOLS+=	patch

.include "../../mk/bsd.prefs.mk"

.if !empty(EXTRACT_USING:M*tar)
EXTRACT_CMD_OPTS${EXTRACT_SUFX}=	-X ${FILESDIR}/exclude -p
.elif !empty(EXTRACT_USING:Mpax)
EXTRACT_CMD_OPTS${EXTRACT_SUFX}=	-c `${CAT} ${FILESDIR}/exclude`
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	extract_file=${_DISTDIR:Q}/${DISTFILES:Q};			\
	cd ${PREFIX}/share/texmf; ${EXTRACT_CMD${EXTRACT_SUFX}}
	cd ${PREFIX}/share/texmf/dvipdfm/config && \
	${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${FILESDIR}/dvipdfm-config.diff && \
	${RM} config.orig

.include "../../mk/bsd.pkg.mk"
