LIB	= randlib
LIBVERSION = 1:3:0
LIBDIR	= ${PREFIX}/lib

OBJ= com.o randlib.o linpack.o

all:	lib$(LIB)

lib$(LIB): $(OBJ)
	@$(LIBTOOL) --mode=link $(CC) -O -o lib$(LIB).la $(OBJ:.o=.lo) \
	-rpath $(LIBDIR) -version-info $(LIBVERSION)

.c.o:
	@$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) -c $*.c

install:
	@$(LIBTOOL) --mode=install install lib$(LIB).la $(LIBDIR)

clean:
	rm -rf *.o *.lo .libs $(LIB).la