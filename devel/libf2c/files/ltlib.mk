# building library using libtool, simplified

.include "bsd.init.mk"
.include <bsd.obj.mk>
.include <bsd.dep.mk>
.-include <bsd.depall.mk>	# it doesn't exist on NetBSD

OBJS+=		$(SRCS:.c=.o)
LTOBJS+=	$(SRCS:.c=.lo)

.SUFFIXES:	.c .lo
.c.lo:
	$(LIBTOOL) --mode=compile $(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
lib$(LIB).la:	$(LTOBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $(LTOBJS) $(LDFLAGS) -rpath $(LIBDIR) -version-info $(SHLIB_MAJOR):$(SHLIB_MINOR)

$(LTOBJS):	$(DPSRCS)

all:		lib$(LIB).la

install:	lib$(LIB).la
	$(LIBTOOL) --mode=install $(INSTALL) $(RENAME) $(PRESERVE) $(COPY) $(INSTPRIV) \
	    -o $(LIBOWN) -g $(LIBGRP) -m $(LIBMODE) \
		lib$(LIB).la $(DESTDIR)$(LIBDIR)

clean cleandir:
	rm -f $(CLEANFILES)
	rm -f lib$(LIB).la $(LTOBJS) $(OBJS)
	rm -rf .libs

LIBTOOL?=	libtool
LIBDIR?=	/usr/local/lib	# required

.include "bsd.inc.mk"
