
AM_CPPFLAGS = \
	-DPACKAGE_SYSCONF_DIR=\""$(sysconfdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_BIN_DIR=\""$(bindir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_LOCALSTATEDIR=\""$(localstatedir)"\" \
	-I$(top_srcdir) -I$(top_srcdir)/hald -I$(top_srcdir)/libhal -I$(top_srcdir)/libhal-storage \
	@GLIB_CFLAGS@ @DBUS_CFLAGS@

if HALD_COMPILE_NETBSD
libexec_PROGRAMS = hald-probe-storage hald-probe-volume
endif

hald_probe_storage_SOURCES = probe-storage.c cdutils.c fsutils.c ../../logger.c
hald_probe_storage_LDADD = $(top_builddir)/libhal/libhal.la @GLIB_LIBS@ -lprop

hald_probe_volume_SOURCES = probe-volume.c cdutils.c fsutils.c ../../logger.c 
hald_probe_volume_LDADD = $(top_builddir)/libhal/libhal.la @GLIB_LIBS@ -lprop

