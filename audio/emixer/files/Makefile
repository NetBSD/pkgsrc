#	$NetBSD: Makefile,v 1.5 2001/06/19 15:57:39 jlam Exp $

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lncurses -lossaudio

install:
	${BSD_INSTALL_PROGRAM}	emixer	${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${PREFIX}/share/doc/emixer.readme
