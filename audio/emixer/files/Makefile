#	$NetBSD: Makefile,v 1.7 2009/07/08 15:52:33 joerg Exp $

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lncurses ${LIBOSSAUDIO}

install:
	${BSD_INSTALL_PROGRAM}	emixer	${DESTDIR}${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${DESTDIR}${PREFIX}/share/doc/emixer.readme
