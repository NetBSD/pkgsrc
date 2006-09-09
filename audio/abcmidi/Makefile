# $NetBSD: Makefile,v 1.3 2006/09/09 02:41:54 obache Exp $
#

DISTNAME=	abcMIDI-${ABCMIDIVER}
PKGNAME=	abcmidi-${ABCMIDIVER}
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.pugmarks.com/~seymour/runabc/
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/abcmidi
MAKE_FILE=	makefile

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://abc.sourceforge.net/abcMIDI/
COMMENT=	Music utilities for abc

ABCMIDIVER=	2006-04-22

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} abc2abc abc2midi mftext \
		midi2abc midicopy yaps ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/abcmidi
	${INSTALL_DATA} ${WRKSRC}/demo.abc ${PREFIX}/share/examples/abcmidi/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/abcmidi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} AUTHORS CHANGES \
		abcguide.txt abcmatch.txt gpl.txt history.txt readme.txt \
		yapshelp.txt ${PREFIX}/share/doc/abcmidi/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/abcmidi/programming
	cd ${WRKSRC}/doc/programming && ${INSTALL_DATA} abc2midi.txt \
		coding.txt midi2abc.txt split.abc yaps.txt \
		${PREFIX}/share/doc/abcmidi/programming/
	${INSTALL_MAN} ${WRKSRC}/doc/abc2abc.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/abc2midi.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/mftext.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/midi2abc.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/midicopy.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/yaps.1 ${PREFIX}/man/man1/

.include "../../mk/bsd.pkg.mk"
