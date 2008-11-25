
AM_CPPFLAGS = \
	-DPACKAGE_SYSCONF_DIR=\""$(sysconfdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_BIN_DIR=\""$(bindir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_LOCALSTATEDIR=\""$(localstatedir)"\" \
        -I$(top_srcdir) -I$(top_srcdir)/hald -I$(top_srcdir)/libhal -I$(top_srcdir)/libhal-storage \
        @GLIB_CFLAGS@ @DBUS_CFLAGS@

if HALD_COMPILE_NETBSD
libexec_PROGRAMS  = hald-addon-storage
endif

hald_addon_storage_SOURCES = addon-storage.c ../../logger.c
hald_addon_storage_LDADD = $(top_builddir)/libhal/libhal.la

