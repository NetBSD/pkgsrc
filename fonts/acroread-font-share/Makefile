# $NetBSD: Makefile,v 1.1.1.1 2000/05/12 20:39:12 sakamoto Exp $
#

DISTNAME=	font-share
CATEGORIES=	fonts
DISTFILES=	korfont${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/KORKIT
TAR_FILE=	${WRKSRC}/LANGCOM.TAR

PLIST_SUBST+=	MKDIR="${MKDIR}" CHOWN="${CHOWN}" CHMOD="${CHMOD}" \
		SHAREOWN="${SHAREOWN}" SHAREGRP="${SHAREGRP}" \
		SHAREMODE="${SHAREMODE}"

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4/Resource

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/Acrobat4/Resource/CIDFont

.include "./Makefile.common"
