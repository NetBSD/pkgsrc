#
#	$Id: Makefile,v 1.1.1.1 2003/02/22 01:05:18 rh Exp $
#
# Package Makefile for libsieve
#
OBJS=	sieve_err.o sieve.o sieve-lex.o comparator.o interp.o message.o script.o tree.o addr.o addr-lex.o md5.o

.c.o:
	${LIBTOOL} --mode=compile ${CC} ${CPPFLAGS} ${CFLAGS} -c ${.IMPSRC}

#.y.c:
#	yacc -d ${.IMPSRC}
#	mv -f y.tab.c ${.TARGET}
#	mv -f y.tab.h ${.TARGET:.c=.h}

all: libsieve.la

libsieve.la: ${OBJS}
	${LIBTOOL} --mode=link ${CC} -o ${.TARGET} ${OBJS:.o=.lo} -rpath ${PREFIX}/lib -version-info 1:0 ${LDFLAGS}
