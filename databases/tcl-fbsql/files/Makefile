MYSQLLIBDIR = ${PREFIX}/lib/mysql
MYSQLINCDIR = ${PREFIX}/include/mysql

PIC = -fPIC
INCLUDES = -I${PREFIX}/include/tcl -I$(MYSQLINCDIR)
CFLAGS += -Wall $(PIC) $(INCLUDES)

LDFLAGS =  -lz $(MYSQLLIBDIR)/libmysqlclient.la

all:	fbsql.so 

fbsql.lo: fbsql.c
	$(LIBTOOL) --mode=compile ${CC} ${CFLAGS} -c fbsql.c
fbsql.so: fbsql.lo
	$(LIBTOOL) --mode=link ${CC} -shared -o $@  fbsql.lo $(LDFLAGS)

clean:
	-rm -f core *.o fbsql.so
