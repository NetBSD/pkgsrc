# $NetBSD: Makefile,v 1.10 2020/05/20 06:09:06 rillig Exp $

DISTNAME=	mpegaudio
PKGNAME=	mpegaudio-3.9
CATEGORIES=	audio
MASTER_SITES=	# empty
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	MPEG/audio Layer 1 and Layer 2 encoder/decoder package

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

# common.c: In function 'aiff_read_headers':
# common.c:729:28: error: array subscript has type 'char' [-Werror=char-subscripts]
#              temp_sampleRate[i] = CommChunk.sampleRate[i];
#                             ^
# common.c:729:54: error: array subscript has type 'char' [-Werror=char-subscripts]
#              temp_sampleRate[i] = CommChunk.sampleRate[i];
#                                                       ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

post-install:
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${FILESDIR}/mpeg_musicout.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
