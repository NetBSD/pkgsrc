same_OBJECTS=	same.o crc32.o

all: same

install: all
	${BSD_INSTALL_PROGRAM} same ${PREFIX}/bin/same
	${BSD_INSTALL_MAN} same.1 ${PREFIX}/man/man1/same.1

.c.o:
	${CC} ${CPPFLAGS} ${CFLAGS} -c $< -o $@

same: ${same_OBJECTS}
	${CC} ${LDFLAGS} $(same_OBJECTS) ${LIBS} -o $@

.PHONY: all install
