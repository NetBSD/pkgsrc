CFLAGS	= -O2 -fomit-frame-pointer -freg-struct-return
INCLUDES= -I${GC_PREFIX}/include -I${X11BASE}/include -I${MESA_PREFIX}/include
LDFLAGS	= -L${GC_PREFIX}/lib -L${X11BASE}/lib -L${MESA_PREFIX}/lib
LIBS	= -lgc -lm

all-32:	stalin-32 libstalin.a

all-alpha: stalin-alpha libstalin.a

OPTIONS = -I ./include -On -du -dI -t -c -db \
          -clone-size-limit 0 -split-even-if-no-widening \
          -do-not-align-strings \
          -treat-all-symbols-as-external \
          -do-not-index-constant-structure-types-by-expression \
          -do-not-index-allocated-structure-types-by-expression

stalin-32: stalin-32.o
	$(CC) -O -o stalin stalin-32.o $(LDFLAGS) $(LIBS)

LIBOBJS = xlib-c.o gl-c.o

libstalin.a: include/xlib-c.o include/gl-c.o
	$(AR) cru $@ $(LIBOBJS)
	$(RANLIB) $@

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<
