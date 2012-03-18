YAJL_MAJOR=	1
YAJL_MINOR=	0
YAJL_MICRO=	9

SRCS=	yajl.c yajl_lex.c yajl_parser.c yajl_buf.c \
	yajl_encode.c yajl_gen.c yajl_alloc.c

HDRS=	yajl_parser.h yajl_lex.h yajl_buf.h yajl_encode.h yajl_alloc.h

PUB_HDRS=	api/yajl_parse.h api/yajl_gen.h api/yajl_common.h

headers:	$(PUB_HDRS)
	$(MKDIR) ../include/yajl
	$(CP) -f $(PUB_HDRS) ../include/yajl

.c.o:
	$(LIBTOOL) --mode=compile --tag=CC $(CC) -c -I../include \
		-DYAJL_BUILD -DNDEBUG $(CFLAGS) $< -o $(@:.o=.lo)

libyajl.la:	$(SRCS:.c=.o)
	$(LIBTOOL) --mode=link $(CC) -o $@ $(LDFLAGS) $(SRCS:.c=.lo) \
		-version-info $(YAJL_MAJOR):$(YAJL_MINOR) \
		-rpath $(PREFIX)/lib

all: headers libyajl.la

install:	libyajl.la
	$(MKDIR) $(DESTDIR)$(PREFIX)/lib
	$(MKDIR) $(DESTDIR)$(PREFIX)/include/yajl
	$(INSTALL) -m644 $(PUB_HDRS) $(DESTDIR)$(PREFIX)/include/yajl/
	$(LIBTOOL) --mode=install $(INSTALL) libyajl.la $(DESTDIR)$(PREFIX)/lib/
