# $NetBSD: Makefile,v 1.4 2004/01/20 12:15:16 agc Exp $
#

DISTNAME=	font-share
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 5 (common base)

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR="${MKDIR}" CHOWN="${CHOWN}" CHMOD="${CHMOD}" \
		SHAREOWN="${SHAREOWN}" SHAREGRP="${SHAREGRP}" \
		SHAREMODE="${SHAREMODE}"

.include "./Makefile.common"
