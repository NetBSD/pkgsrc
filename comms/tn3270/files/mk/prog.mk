#	$NetBSD: prog.mk,v 1.1 2010/01/17 01:41:33 dholland Exp $

OBJS=$(SRCS:T:R:=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBS) -o $(PROG)

.for S in $(SRCS:M*.c)
$(S:T:R).o: $(S)
	$(CC) $(CFLAGS) -c $(S)
.endfor

.for S in $(SRCS:M*.y)
$(S:T:R).o: $(S)
	$(YACC) -o $(S:.y=.c) $(S)
	$(CC) $(CFLAGS) -c $(S:.y=.c)
.endfor

genfiles: $(GENFILES)

depend:
	$(MAKE) genfiles
	$(MKDEP) $(CFLAGS) $(SRCS) > .depend

-include .depend

clean distclean:
	rm -f $(PROG) *.o $(SRCS:M*.y:.y=.c) $(GENFILES)

.PHONY: all genfiles depend clean distclean
