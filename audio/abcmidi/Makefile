# $NetBSD: Makefile,v 1.7 2009/10/10 08:33:24 wiz Exp $
#

DISTNAME=	abcMIDI-${ABCMIDIVER}
PKGNAME=	abcmidi-${ABCMIDIVER:S/-//g}
CATEGORIES=	audio
MASTER_SITES=	http://ifdo.pugmarks.com/~seymour/runabc/
EXTRACT_SUFX=	.zip
WRKSRC=		${WRKDIR}/abcmidi
MAKE_FILE=	makefile

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://abc.sourceforge.net/abcMIDI/
COMMENT=	Music utilities for abc

ABCMIDIVER=	2006-04-22

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 \
			share/doc/abcmidi/programming share/examples/abcmidi

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} abc2abc abc2midi mftext \
		midi2abc midicopy yaps ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/demo.abc \
		${DESTDIR}${PREFIX}/share/examples/abcmidi
	cd ${WRKSRC}/doc && ${INSTALL_DATA} AUTHORS CHANGES \
		abcguide.txt abcmatch.txt gpl.txt history.txt readme.txt \
		yapshelp.txt ${DESTDIR}${PREFIX}/share/doc/abcmidi
	cd ${WRKSRC}/doc/programming && ${INSTALL_DATA} abc2midi.txt \
		coding.txt midi2abc.txt split.abc yaps.txt \
		${DESTDIR}${PREFIX}/share/doc/abcmidi/programming
	${INSTALL_MAN} ${WRKSRC}/doc/abc2abc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/abc2midi.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/mftext.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/midi2abc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/midicopy.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/yaps.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
