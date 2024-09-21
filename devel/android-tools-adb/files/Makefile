# $FreeBSD: 372832 $
# $NetBSD: Makefile,v 1.1 2024/09/21 13:14:58 abs Exp $

SRCS+= adb.c
SRCS+= adb_client.c
SRCS+= adb_auth_host.c
SRCS+= commandline.c
SRCS+= console.c
SRCS+= file_sync_client.c
SRCS+= fdevent.c
ifeq ("${OPSYS}", "FreeBSD")
SRCS+= get_my_path_freebsd.c
else ifeq ("${OPSYS}", "DragonFly")
SRCS+= get_my_path_freebsd.c
else ifeq ("${OPSYS}", "Darwin")
SRCS+= get_my_path_darwin.c
else
SRCS+= get_my_path_linux.c
endif
SRCS+= services.c
SRCS+= sockets.c
SRCS+= transport.c
SRCS+= transport_local.c
SRCS+= transport_usb.c
SRCS+= usb_libusb.c
SRCS+= usb_vendors.c

VPATH+= ../libcutils
SRCS+= socket_inaddr_any_server.c
SRCS+= socket_local_client.c
SRCS+= socket_local_server.c
SRCS+= socket_loopback_client.c
SRCS+= socket_loopback_server.c
SRCS+= socket_network_client.c
SRCS+= load_file.c

VPATH+= ../libzipfile
SRCS+= centraldir.c
SRCS+= zipfile.c


CPPFLAGS+= -DADB_HOST=1
CPPFLAGS+= -DHAVE_FORKEXEC=1
CPPFLAGS+= -DHAVE_SYMLINKS
CPPFLAGS+= -DHAVE_TERMIO_H
CPPFLAGS+= -DHAVE_SYS_SOCKET_H
CPPFLAGS+= -D_FILE_OFFSET_BITS=64
CPPFLAGS+= -I.
CPPFLAGS+= -I../include

LIBS+= -lc -pthread -lz -lcrypto -lusb-1.0

OBJS= $(SRCS:.c=.o)

all: adb

adb: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

install: adb
	${BSD_INSTALL_PROGRAM} adb ${DESTDIR}${PREFIX}/bin/

clean:
	rm -rf $(OBJS) adb
