# $NetBSD: Makefile,v 1.5 2003/07/17 21:36:43 grant Exp $
#

DISTNAME=	font-share
WRKSRC=		${WRKDIR}/KORKIT
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 4.0 (common base)

TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR="${MKDIR}" CHOWN="${CHOWN}" CHMOD="${CHMOD}" \
		SHAREOWN="${SHAREOWN}" SHAREGRP="${SHAREGRP}" \
		SHAREMODE="${SHAREMODE}"

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4/Resource

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4/Resource/CIDFont

.include "./Makefile.common"
