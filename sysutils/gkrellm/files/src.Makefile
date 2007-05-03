include ../Makefile.inc

PACKAGE ?= gkrellm

SMC_LIBS ?= -L$(X11BASE)/lib -Wl,-R$(X11BASE)/lib -lSM -lICE

GKRELLM_INCLUDES = gkrellm.h gkrellm-public-proto.h

PKG_INCLUDE = `$(PKG_CONFIG) --cflags gtk+-2.0 gthread-2.0`
PKG_LIB = `$(PKG_CONFIG) --libs gtk+-2.0 gthread-2.0`

CFLAGS?=	-O2
FLAGS = -I.. $(PKG_INCLUDE) $(GTOP_INCLUDE)
FLAGS+= $(PTHREAD_INC)

ifeq ($(DEBUG),yes)
    FLAGS += -g
endif

ifeq ($(ENABLE_NLS),yes)
    FLAGS += -DENABLE_NLS -DLOCALEDIR=\"$(LOCALEDIR)\"
endif
ifneq ($(PACKAGE),gkrellm)
    FLAGS += -DPACKAGE=\"$(PACKAGE)\"
endif

ifeq ($(HAVE_GETADDRINFO),1)
    FLAGS += -DHAVE_GETADDRINFO
endif

SSL_TYPE?=	gnutls openssl
ifeq ($(without-gnutls),1)
SSL_TYPE=	$(filter-out gnutls, $(SSL_TYPE))
endif
ifeq ($(without-gnutls),yes)
SSL_TYPE=	$(filter-out gnutls, $(SSL_TYPE))
endif
ifeq ($(without-ssl),1)
SSL_TYPE=	$(filter-out openssl, $(SSL_TYPE))
endif
ifeq ($(without-ssl),yes)
SSL_TYPE=	$(filter-out openssl, $(SSL_TYPE))
endif
ifeq ($(filter gnutls, $(SSL_TYPE)),)
CONFIGURE_ARGS+=	--without-gnutls
endif
ifeq ($(filter openssl, $(SSL_TYPE)),)
CONFIGURE_ARGS+=	--without-openssl
endif

USE_LIBSENSORS?=	yes
ifeq ($(without-libsensors),yes)
USE_LIBSENSORS=		no
endif
ifeq ($(without-libsensors),1)
USE_LIBSENSORS=		no
endif
ifeq ($(USE_LIBSENSORS),no)
CONFIGURE_ARGS+=	--without-libsensors
endif

GREP?=		grep

DUMMY_VAR:=	$(shell ./configure $(CONFIGURE_ARGS))
HAVE_GNUTLS=	$(shell $(GREP) -c HAVE_GNUTLS configure.h)
HAVE_SSL=	$(shell $(GREP) -c HAVE_SSL configure.h)
HAVE_LIBSENSORS=	$(shell $(GREP) -c HAVE_LIBSENSORS configure.h)

ifeq ($(HAVE_GNUTLS),1)
SSL_LIBS?=	-lgnutls-openssl
else
ifeq ($(HAVE_SSL),1)
SSL_LIBS?=	-lssl -lcrypto
NEED_MD5=	no
MD5_LIBS=
endif
endif

ifeq ($(HAVE_LIBSENSORS),1)
SENSORS_LIBS?=	-lsensors
endif

LIBS = $(PKG_LIB) $(GTOP_LIBS) $(SMC_LIBS) $(SYS_LIBS) $(MD5_LIBS) $(SSL_LIBS) \
	$(SENSORS_LIBS)

override CFLAGS += -Wall $(FLAGS)

OBJS =	main.o alerts.o battery.o base64.o clock.o cpu.o disk.o fs.o \
	hostname.o inet.o mail.o mem.o net.o proc.o sensors.o uptime.o \
	chart.o panel.o config.o gui.o krell.o plugins.o pixops.o \
	smbdes.o smbencrypt.o smbmd4.o smbutil.o \
	client.o utils.o winops-x11.o sysdeps-unix.o deprecated.o

ifeq ($(NEED_MD5),yes)
OBJS+=	md5c.c
endif

all:	build

build:	gkrellm

gkrellm static: $(OBJS)
	$(CC) $(OBJS) -o gkrellm$(if $(findstring static,$@),.static -static) $(LIBS) $(LINK_FLAGS)

install: gkrellm
	$(INSTALL_DIR) $(INSTALLDIR)
	$(INSTALL_DIR) $(INCLUDEDIR)/gkrellm2
	$(INSTALL_DIR) $(MANDIR)
	$(INSTALL_BIN) $(STRIP) gkrellm $(INSTALLDIR)/$(PACKAGE)
	$(INSTALL_DATA) $(GKRELLM_INCLUDES) $(INCLUDEDIR)/gkrellm2
	$(INSTALL_DATA) ../gkrellm.1 $(MANDIR)/$(PACKAGE).1

uninstall:
	rm -f $(INSTALLDIR)/$(PACKAGE)
	rm -rf $(INCLUDEDIR)/gkrellm2
	rm -f $(MANDIR)/$(PACKAGE).1

clean:
	rm -f *.o *~ *.bak configure.h configure.log gkrellm core

IMAGES = \
	../pixmaps/frame_top.xpm \
	../pixmaps/frame_bottom.xpm \
	../pixmaps/frame_left.xpm \
	../pixmaps/frame_right.xpm \
	\
	../pixmaps/button_panel_out.xpm \
	../pixmaps/button_panel_in.xpm \
	../pixmaps/button_meter_out.xpm \
	../pixmaps/button_meter_in.xpm \
	\
	../pixmaps/bg_chart.xpm \
	../pixmaps/bg_grid.xpm  \
	../pixmaps/bg_panel.xpm \
	../pixmaps/bg_meter.xpm \
	\
	../pixmaps/data_in.xpm \
	../pixmaps/data_in_grid.xpm \
	../pixmaps/data_out.xpm \
	../pixmaps/data_out_grid.xpm \
	\
	../pixmaps/net/decal_net_leds.xpm \
	../pixmaps/decal_misc.xpm \
	../pixmaps/decal_alarm.xpm \
	../pixmaps/decal_warn.xpm \
	\
	../pixmaps/krell_panel.xpm \
	../pixmaps/krell_meter.xpm \
	../pixmaps/krell_slider.xpm \
	../pixmaps/krell_mini.xpm \
	../pixmaps/fs/bg_panel.xpm \
	../pixmaps/host/bg_panel.xpm \
	../pixmaps/mail/decal_mail.xpm \
	../pixmaps/mail/krell_mail.xpm \
	../pixmaps/mail/krell_mail_daemon.xpm \
	../pixmaps/timer/bg_panel.xpm \
	../pixmaps/timer/bg_timer.xpm \
	../pixmaps/timer/decal_timer_button.xpm \
	../pixmaps/uptime/bg_panel.xpm \
	\
	../pixmaps/gkrellmms/bg_panel.xpm \
	../pixmaps/gkrellmms/spacer_top.xpm \
	../pixmaps/gkrellmms/spacer_bottom.xpm \
	../pixmaps/gkrellmms/bg_scroll.xpm \
	../pixmaps/pmu/bg_panel.xpm \
	../pixmaps/pmu/spacer_top.xpm \
	../pixmaps/pmu/spacer_bottom.xpm \
	../pixmaps/volume/bg_panel.xpm \
	../pixmaps/volume/spacer_top.xpm \
	../pixmaps/volume/spacer_bottom.xpm \
	../pixmaps/bg_separator.xpm

SYSDEPS_SRC = sysdeps/bsd-common.c sysdeps/bsd-net-open.c sysdeps/freebsd.c \
	sysdeps/gtop.c sysdeps/linux.c sysdeps/netbsd.c sysdeps/openbsd.c \
	sysdeps/solaris.c sysdeps/darwin.c sysdeps/sensors-common.c \
	sysdeps/dragonfly.c

GKRELLM_H = gkrellm.h gkrellm-private.h
GKRELLM_H_SYS = gkrellm.h gkrellm-public-proto.h gkrellm-private.h \
	gkrellm-sysdeps.h

main.o:      main.c $(GKRELLM_H)
alerts.o:    alerts.c $(GKRELLM_H)
battery.o:   battery.c $(GKRELLM_H_SYS)
base64.o:    base64.c
clock.o:     clock.c  $(GKRELLM_H_SYS)
cpu.o:	     cpu.c  $(GKRELLM_H_SYS)
disk.o:      disk.c $(GKRELLM_H_SYS)
fs.o:        fs.c $(GKRELLM_H_SYS)
hostname.o:  hostname.c $(GKRELLM_H_SYS)
inet.o:      inet.c $(GKRELLM_H_SYS)
mail.o:      mail.c md5.h md5global.h ntlm.h $(GKRELLM_H_SYS)
md5c.o:      md5.h md5global.h
smbdes.o:    smbdes.h
smbencrypt.o: smbbyteorder.h smbdes.h smbmd4.h
smbmd4.o:    smbmd4.h
smbutil.o:   ntlm.h smbencrypt.h smbbyteorder.h
mem.o:       mem.c  $(GKRELLM_H_SYS)
net.o:	     net.c  $(GKRELLM_H_SYS)
proc.o:      proc.c  $(GKRELLM_H_SYS)
sensors.o:   sensors.c $(GKRELLM_H_SYS) ../pixmaps/sensors/bg_volt.xpm
uptime.o:    uptime.c $(GKRELLM_H_SYS)
chart.o:     chart.c  $(GKRELLM_H)
panel.o:     panel.c  $(GKRELLM_H)
config.o:    config.c  $(GKRELLM_H) $(IMAGES)
krell.o:     krell.c  $(GKRELLM_H)
gui.o:       gui.c  $(GKRELLM_H)
plugins.o:   plugins.c $(GKRELLM_H)
pixops.o:    pixops.c $(GKRELLM_H)
client.o:    client.c $(GKRELLM_H)
utils.o:     utils.c $(GKRELLM_H)
sysdeps-unix.o: sysdeps-unix.c $(GKRELLM_H_SYS) $(SYSDEPS_SRC)
winops-x11.o: winops-x11.c $(GKRELLM_H)
deprecated.o: deprecated.c $(GKRELLM_H)
