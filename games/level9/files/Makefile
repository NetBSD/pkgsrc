all: level9

level9: level9.o unix-curses.o
	${CC} ${LDFLAGS} -o level9 level9.o unix-curses.o -lncurses

unix-curses.o: unix-curses.c ../level9.h
	${CC} -I.. ${CFLAGS} -c unix-curses.c

level9.o: ../level9.c ../level9.h
	${CC} -I.. ${CFLAGS} -c ../level9.c
