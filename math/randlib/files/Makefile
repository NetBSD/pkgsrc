LIB	= randlib
LIBDIR	= ${PREFIX}/lib

OBJS = com.o randlib.o linpack.o

all:	lib$(LIB).la

lib$(LIB).la: $(OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) -o $@ $(OBJS:.o=.lo) \
	-lm -rpath $(LIBDIR) -version-info 0:0

.c.o:
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) -c $*.c

install:  lib$(LIB).la
	$(LIBTOOL) --mode=install $(BSD_INSTALL_DATA) $? $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs lib$(LIB).la
