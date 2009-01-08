helperdir = $(datadir)/PackageKit/helpers/pkgsrc
dist_helper_DATA = pkgsrc-backend.sh

plugindir = $(PK_PLUGIN_DIR)
plugin_LTLIBRARIES = libpk_backend_pkgsrc.la
libpk_backend_pkgsrc_la_SOURCES = pk-backend-pkgsrc.c
libpk_backend_pkgsrc_la_LIBADD = $(PK_PLUGIN_LIBS) $(PKGSRC_LIBS)

libpk_backend_pkgsrc_la_LDFLAGS = -module -avoid-version
libpk_backend_pkgsrc_la_CFLAGS = $(PK_PLUGIN_CFLAGS) $(PKGSRC_CFLAGS)

install-data-hook:
	chmod a+rx $(DESTDIR)$(helperdir)/*.sh
