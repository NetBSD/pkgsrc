#	$NetBSD: Makefile,v 1.8 2013/10/14 13:33:31 roy Exp $

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} -lcurses ${LIBOSSAUDIO}

install:
	${BSD_INSTALL_PROGRAM}	emixer	${DESTDIR}${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${DESTDIR}${PREFIX}/share/doc/emixer.readme
