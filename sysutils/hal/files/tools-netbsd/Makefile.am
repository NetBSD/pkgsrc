## Process this file with automake to produce Makefile.in
# $NetBSD: Makefile.am,v 1.1 2008/11/27 03:32:19 jmcneill Exp $

AM_CPPFLAGS = \
	-DPACKAGE_LIBEXEC_DIR=\""$(libexecdir)"\" \
	-DPACKAGE_SYSCONF_DIR=\""$(sysconfdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_BIN_DIR=\""$(bindir)"\" \
	-DPACKAGE_LOCALSTATEDIR=\""$(localstatedir)"\" \
	-DPACKAGE_SCRIPT_DIR=\""$(libdir)/hal/scripts"\" \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-I$(top_srcdir) -I$(top_srcdir)/libhal -I$(top_srcdir)/libhal-storage \
	@DBUS_CFLAGS@ @GLIB_CFLAGS@ @POLKIT_CFLAGS@

scriptdir = $(libdir)/hal/scripts/netbsd

script_SCRIPTS =					\
	hal-system-power-suspend-netbsd			\
	hal-system-power-shutdown-netbsd		\
	hal-system-power-reboot-netbsd

EXTRA_DIST = $(script_SCRIPTS)

check:
	for f in $(script_SCRIPTS); do \
            echo -n "Validate bash syntax in $$f : "; \
            bash -n $(srcdir)/$$f 2> bash.error;\
            if test -s bash.error; then \
                echo failed; \
                cat bash.error; \
                rm -f bash.error; \
                exit 1; \
            else \
                echo ok; \
                rm -f bash.error; \
            fi; \
        done;

clean-local :
	rm -f *~
