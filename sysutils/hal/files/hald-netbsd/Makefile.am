
SUBDIRS = probing addons .

AM_CPPFLAGS = \
	-DPACKAGE_SYSCONF_DIR=\""$(sysconfdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_BIN_DIR=\""$(bindir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_LOCALSTATEDIR=\""$(localstatedir)"\" \
	-I$(top_srcdir) -I.. \
	@GLIB_CFLAGS@ @DBUS_CFLAGS@ @POLKIT_CFLAGS@ @VOLUME_ID_CFLAGS@

if HALD_COMPILE_NETBSD
noinst_LTLIBRARIES = libhald_netbsd.la
endif

libhald_netbsd_la_SOURCES = \
	osspec.c drvctl.c envsys.c vfsstat.c \
	devinfo.c devinfo_misc.c devinfo_audio.c devinfo_video.c \
	devinfo_mass.c \
	hotplug.c hal-file-monitor.c \
	devinfo_optical.c 
#	devinfo_scsipi.c
#	devinfo_usb.c \
#	devinfo_pci.c

libhald_netbsd_la_LDFLAGS = -lprop @VOLUME_ID_LIBS@
