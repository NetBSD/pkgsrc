## Process this file with automake to produce Makefile.in
# $NetBSD: Makefile.am,v 1.2 2011/01/08 13:39:08 obache Exp $

AM_CPPFLAGS = \
	-DPACKAGE_LIBEXEC_DIR=\""$(libexecdir)"\" \
	-DPACKAGE_SYSCONF_DIR=\""$(sysconfdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_BIN_DIR=\""$(bindir)"\" \
	-DPACKAGE_LOCALSTATEDIR=\""$(localstatedir)"\" \
	-DPACKAGE_SCRIPT_DIR=\""$(libexecdir)/scripts"\" \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-I$(top_srcdir) -I$(top_srcdir)/libhal -I$(top_srcdir)/libhal-storage \
	@DBUS_CFLAGS@ @GLIB_CFLAGS@ @POLKIT_CFLAGS@

scriptdir = $(libexecdir)/scripts/netbsd

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
