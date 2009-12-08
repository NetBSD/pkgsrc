MYSQLLIBDIR = ${PREFIX}/lib/mysql
MYSQLINCDIR = ${PREFIX}/include/mysql

PIC = -fPIC
INCLUDES = -I${PREFIX}/include/tcl -I$(MYSQLINCDIR)
CFLAGS += -Wall $(PIC) $(INCLUDES)

LDFLAGS =  -lz $(MYSQLLIBDIR)/libmysqlclient.la -L$(PREFIX)/lib -ltcl

all:	fbsql.la

fbsql.lo: fbsql.c
	$(LIBTOOL) --mode=compile ${CC} ${CFLAGS} -c fbsql.c
fbsql.la: fbsql.lo
	$(LIBTOOL) --mode=link ${CC} -module -rpath ${PREFIX}/lib/tcl -o fbsql.la  fbsql.lo $(LDFLAGS)

clean:
	-rm -f core *.o fbsql.so
