# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:07 joerg Exp $
#

DISTNAME=	font-share
PKGREVISION=	1
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
