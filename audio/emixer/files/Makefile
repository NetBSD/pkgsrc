#	$NetBSD: Makefile,v 1.3 2000/04/16 02:57:21 mycroft Exp $

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lm

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lncurses -lossaudio

install:
	${BSD_INSTALL_PROGRAM}	emixer	${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${PREFIX}/share/doc/emixer.readme
