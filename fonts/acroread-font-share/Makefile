# $NetBSD: Makefile,v 1.8 2006/02/05 23:09:07 joerg Exp $
#

DISTNAME=	font-share
PKGREVISION=	1
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Asian Font Packs for Acrobat Reader 4.0 (common base)

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR=${MKDIR:Q} CHOWN=${CHOWN:Q} CHMOD=${CHMOD:Q} \
		SHAREOWN=${SHAREOWN:Q} SHAREGRP=${SHAREGRP:Q} \
		SHAREMODE=${SHAREMODE:Q}

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4/Resource

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4/Resource/CIDFont

.include "./Makefile.common"
