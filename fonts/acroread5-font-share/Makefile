# $NetBSD: Makefile,v 1.1.1.1 2002/09/16 05:58:14 uebayasi Exp $
#

DISTNAME=	font-share
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Asian Font Packs for Acrobat Reader 5 (common base)

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR="${MKDIR}" CHOWN="${CHOWN}" CHMOD="${CHMOD}" \
		SHAREOWN="${SHAREOWN}" SHAREGRP="${SHAREGRP}" \
		SHAREMODE="${SHAREMODE}"

.include "./Makefile.common"
