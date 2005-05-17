# $NetBSD: Makefile,v 1.30 2005/05/17 22:00:13 jlam Exp $
#

DISTNAME=	tetex-texmf-2.0.2
PKGNAME=	teTeX-share-2.0.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	listings${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Machine-independent part of teTeX, version 2

SITES_listings${EXTRACT_SUFX}= ${LOCAL_PORTS}

CONFLICTS+=	teTeX2-share-[0-9]*

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	teTeX
EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_GNU_TOOLS+=		patch

.include "../../mk/bsd.prefs.mk"

# Don't extract the files listed in ${FILESDIR}/exclude, and preserve
# permissions.
#
.if !empty(EXTRACT_USING:M*tar)
EXTRACT_CMD_OPTS${EXTRACT_SUFX}=	-X ${FILESDIR}/exclude -p
.elif !empty(EXTRACT_USING:Mpax)
EXTRACT_CMD_OPTS${EXTRACT_SUFX}=	-c `${CAT} ${FILESDIR}/exclude`
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/texmf
	distfiles=${DISTFILES:Q};					\
	for i in $$distfiles; do					\
		extract_file=${_DISTDIR:Q}"/$$i";			\
		cd ${PREFIX}/share/texmf; ${EXTRACT_CMD${EXTRACT_SUFX}}; \
	done
	cd ${PREFIX}/share/texmf/dvipdfm/config && \
	${PATCH} ${_PATCH_BACKUP_ARG} .orig < ${FILESDIR}/dvipdfm-config.diff && \
	${RM} config.orig

.include "../../mk/bsd.pkg.mk"
