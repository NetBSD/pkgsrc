all: splitmrb zapres helpdeco

CFLAGS+=-g

splitmrb: splitmrb.c
	${CC} ${CFLAGS} -o splitmrb splitmrb.c
zapres: zapres.c compat.o
	${CC} ${CFLAGS} -o zapres zapres.c compat.o
helpdeco: helpdeco.c helpdec1.c compat.o
	${CC} ${CFLAGS} -o helpdeco helpdeco.c helpdec1.c compat.o
compat.o: compat.c

clean:
	rm -f *.o helpdeco zapres splitmrb
