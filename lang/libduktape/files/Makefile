# ***** WARNING ***** EDIT THIS FILE WITH A UTF-AWARE EDITOR

srcdir= src
VPATH= src

prefix= ${PREFIX}
exec_prefix= ${PREFIX}
LIBDIR= $(exec_prefix)/lib
INCDIR= $(prefix)/include

SHELL=/bin/sh

CFLAGS= -I. -I$(srcdir)
OBJS= duktape.o
LIBS= libduktape.a
ARFLAGS= crv

all:	${LIBS}

$(LIBS) : $(OBJS)
	${LIBTOOL} --mode=link --tag=CC cc -o ${.TARGET:.a=.la} ${OBJS:.o=.lo} -rpath ${PREFIX}/lib -version-info 0:0

${OBJS}: duktape.c duktape.h duk_config.h
	${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} -c duktape.c

install: $(LIBS)
	mkdir -p ${DESTDIR}$(LIBDIR) ${DESTDIR}$(INCDIR)
	${LIBTOOL} --mode=install ${BSD_INSTALL_DATA} ${LIBS:.a=.la} ${DESTDIR}${PREFIX}/lib
	$(BSD_INSTALL_DATA) duktape.h ${DESTDIR}$(INCDIR)
	$(BSD_INSTALL_DATA) duk_config.h ${DESTDIR}$(INCDIR)

clean:
	rm -f $(OBJS) $(LIBS)
	
cleandist:
	rm -f $(OBJS) $(LIBS)
