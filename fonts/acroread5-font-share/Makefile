# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:55 jmmv Exp $
#

DISTNAME=	font-share
WRKSRC=		${WRKDIR}/KORKIT
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	Asian Font Packs for Acrobat Reader 5 (common base)

TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR="${MKDIR}" CHOWN="${CHOWN}" CHMOD="${CHMOD}" \
		SHAREOWN="${SHAREOWN}" SHAREGRP="${SHAREGRP}" \
		SHAREMODE="${SHAREMODE}"

.include "./Makefile.common"
