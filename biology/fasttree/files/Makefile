
BIN =		FastTree
SRC =		FastTree*.c
CC ?=		gcc
CFLAGS ?=	-O3
CFLAGS +=	-DOPENMP -fopenmp

MKDIR ?=	mkdir
INSTALL ?=	install
PREFIX ?=	/usr/local

.PHONY:	all install clean

all:	${BIN}

${BIN}: ${SRC} Makefile
	${CC} ${CFLAGS} ${SRC} -o ${BIN} ${LDFLAGS} -lm

install: ${BIN}
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${INSTALL} -s -c ${BIN} ${DESTDIR}${PREFIX}/bin

clean:
	${RM} -f ${BIN}
