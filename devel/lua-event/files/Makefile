# $NetBSD: Makefile,v 1.1 2020/07/11 12:37:25 nia Exp $

CFLAGS+=	-fPIC -Wall -I../include
LDFLAGS+=	-levent -shared

OBJS+=	buffer_event.o
OBJS+=	event_buffer.o
OBJS+=	event_callback.o
OBJS+=	luaevent.o
OBJS+=	utility.o

all: core.so

.c.o:
	$(CC) $(CFLAGS) -c $<

core.so: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
