#	$NetBSD: Makefile,v 1.2 1999/12/20 03:28:38 hubertf Exp $

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lm

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lslang -lncurses -lossaudio

install:
	${BSD_INSTALL_PROGRAM}	emixer	${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${PREFIX}/share/doc/emixer.readme
