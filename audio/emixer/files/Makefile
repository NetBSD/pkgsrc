#	$NetBSD: Makefile,v 1.4 2001/01/07 03:10:50 wiz Exp $

.if defined(NEED_NCURSES) && ${NEED_NCURSES} == "YES"
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lm
CURSESLIBS=	-lncurses
.else
CURSESLIBS=	-lcurses
.endif

all: emixer
emixer: main.o
	${CC} ${LDFLAGS} -o ${.TARGET}  ${.ALLSRC} ${CURSESLIBS} -lossaudio

install:
	${BSD_INSTALL_PROGRAM}	emixer	${PREFIX}/bin/emixer
	${BSD_INSTALL_DATA}	readme  ${PREFIX}/share/doc/emixer.readme
