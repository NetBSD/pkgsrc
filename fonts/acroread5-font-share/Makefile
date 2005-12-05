# $NetBSD: Makefile,v 1.5 2005/12/05 20:50:13 rillig Exp $
#

DISTNAME=	font-share
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 5 (common base)

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR=${MKDIR:Q} CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} \
		SHAREOWN=${SHAREOWN:Q} SHAREGRP=${SHAREGRP:Q} \
		SHAREMODE=${SHAREMODE:Q}

.include "./Makefile.common"
