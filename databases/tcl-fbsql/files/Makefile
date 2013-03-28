CFLAGS += -Wall -I${PREFIX}/include/tcl -I$(MYSQLINCDIR)

LDFLAGS = -Wl,-rpath,$(MYSQLLIBDIR) -L$(MYSQLLIBDIR) -lmysqlclient -L$(PREFIX)/lib -Wl,-rpath,$(PREFIX)/lib -ltcl -lz

all:	fbsql.la

fbsql.lo: fbsql.c
	$(LIBTOOL) --mode=compile ${CC} ${CFLAGS} -c fbsql.c
fbsql.la: fbsql.lo
	$(LIBTOOL) --mode=link ${CC} -module -rpath ${PREFIX}/lib/tcl -o fbsql.la  fbsql.lo $(LDFLAGS)

clean:
	-rm -f core *.o fbsql.so
