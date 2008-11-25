
SUBDIRS = probing addons .

AM_CPPFLAGS = \
	-DPACKAGE_SYSCONF_DIR=\""$(sysconfdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_BIN_DIR=\""$(bindir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_LOCALSTATEDIR=\""$(localstatedir)"\" \
	-I$(top_srcdir) -I.. \
	@GLIB_CFLAGS@ @DBUS_CFLAGS@ @POLKIT_CFLAGS@

if HALD_COMPILE_NETBSD
noinst_LTLIBRARIES = libhald_netbsd.la
endif

libhald_netbsd_la_SOURCES = \
	osspec.c drvctl.c \
	devinfo.c devinfo_misc.c \
	hotplug.c hal-file-monitor.c
#	devinfo_pci.c devinfo_storage.c devinfo_usb.c

libhald_netbsd_la_LDFLAGS = -lprop
