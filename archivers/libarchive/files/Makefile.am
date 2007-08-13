## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = foreign subdir-objects

BUILT_SOURCES = libarchive/test/list.h libarchive/archive.h

EXTRA_DIST= version				\
	config.h.in				\
	examples				\
	libarchive/test/list.h			\
	tar/test				\
	tar/getdate.c				\
	cpio

# Clean out some unneeded files and directories
# that get picked up as part of the directories in EXTRA_DIST above.
dist-hook:
	rm -rf `find $(distdir) -name CVS -type d`
	rm -rf `find $(distdir) -name .svn -type d`
	rm -f `find $(distdir) -name '*~'`
	rm -f `find $(distdir) -name '*.out'`
	rm -f `find $(distdir) -name '*.core'`
	rm -f $(distdir)/*/Makefile

distclean-local:
	-rm -f tar/getdate.c tar/getdate.h
	-rm -f libarchive/test/list.h
	-rm -rf autom4te.cache/
	-rm -f *~

# Always build libarchive, regardless
lib_LTLIBRARIES=	libarchive.la
bin_PROGRAMS=	$(bsdtar_programs)
check_PROGRAMS= libarchive_test
dist_man_MANS=$(libarchive_dist_man_MANS) $(bsdtar_dist_man_MANS)
TESTS= libarchive_test

#
# Libarchive headers, source, etc.
#
#

include_HEADERS= libarchive/archive_entry.h
# Note: archive.h is built from archive.h.in, so don't
# include archive.h in the distfile, but do install it.
nodist_include_HEADERS= libarchive/archive.h

libarchive_la_SOURCES=						\
	libarchive/archive_check_magic.c			\
	libarchive/archive_entry.c				\
	libarchive/archive_entry.h				\
	libarchive/archive_entry_copy_stat.c			\
	libarchive/archive_entry_private.h			\
	libarchive/archive_entry_stat.c				\
	libarchive/archive_platform.h				\
	libarchive/archive_private.h				\
	libarchive/archive_read.c				\
	libarchive/archive_read_data_into_fd.c			\
	libarchive/archive_read_extract.c			\
	libarchive/archive_read_open_fd.c			\
	libarchive/archive_read_open_file.c			\
	libarchive/archive_read_open_filename.c			\
	libarchive/archive_read_open_memory.c			\
	libarchive/archive_read_private.h			\
	libarchive/archive_read_support_compression_all.c	\
	libarchive/archive_read_support_compression_bzip2.c	\
	libarchive/archive_read_support_compression_compress.c	\
	libarchive/archive_read_support_compression_gzip.c	\
	libarchive/archive_read_support_compression_none.c	\
	libarchive/archive_read_support_compression_program.c	\
	libarchive/archive_read_support_format_all.c		\
	libarchive/archive_read_support_format_ar.c		\
	libarchive/archive_read_support_format_cpio.c		\
	libarchive/archive_read_support_format_empty.c		\
	libarchive/archive_read_support_format_iso9660.c	\
	libarchive/archive_read_support_format_tar.c		\
	libarchive/archive_read_support_format_zip.c		\
	libarchive/archive_string.c				\
	libarchive/archive_string.h				\
	libarchive/archive_string_sprintf.c			\
	libarchive/archive_util.c				\
	libarchive/archive_virtual.c				\
	libarchive/archive_write.c				\
	libarchive/archive_write_disk.c				\
	libarchive/archive_write_disk_private.h			\
	libarchive/archive_write_disk_set_standard_lookup.c	\
	libarchive/archive_write_open_fd.c			\
	libarchive/archive_write_open_file.c			\
	libarchive/archive_write_open_filename.c		\
	libarchive/archive_write_open_memory.c			\
	libarchive/archive_write_private.h			\
	libarchive/archive_write_set_compression_bzip2.c	\
	libarchive/archive_write_set_compression_gzip.c		\
	libarchive/archive_write_set_compression_none.c		\
	libarchive/archive_write_set_compression_program.c	\
	libarchive/archive_write_set_format.c			\
	libarchive/archive_write_set_format_ar.c		\
	libarchive/archive_write_set_format_by_name.c		\
	libarchive/archive_write_set_format_cpio.c		\
	libarchive/archive_write_set_format_cpio_newc.c		\
	libarchive/archive_write_set_format_pax.c		\
	libarchive/archive_write_set_format_shar.c		\
	libarchive/archive_write_set_format_ustar.c		\
	libarchive/config_freebsd.h				\
	libarchive/config_windows.h				\
	libarchive/filter_fork.c				\
	libarchive/filter_fork.h

# archive.h ends up in the build directory, so make sure we can find it.
libarchive_la_CPPFLAGS=-I$(top_builddir)/libarchive
libarchive_la_LDFLAGS= -version-info $(ARCHIVE_LIBTOOL_VERSION)

libarchive_dist_man_MANS=					\
	libarchive/archive_entry.3				\
	libarchive/archive_read.3				\
	libarchive/archive_util.3				\
	libarchive/archive_write.3				\
	libarchive/archive_write_disk.3				\
	libarchive/libarchive.3					\
	libarchive/libarchive_internals.3			\
	libarchive/libarchive-formats.5				\
	libarchive/tar.5

#
#
# libarchive_test program
#
#
libarchive_test_SOURCES=					\
	$(libarchive_la_SOURCES)				\
	libarchive/test/main.c					\
	libarchive/test/read_open_memory.c			\
	libarchive/test/test.h					\
	libarchive/test/test_acl_basic.c			\
	libarchive/test/test_acl_pax.c				\
	libarchive/test/test_archive_api_feature.c		\
	libarchive/test/test_bad_fd.c				\
	libarchive/test/test_entry.c				\
	libarchive/test/test_read_compress_program.c		\
	libarchive/test/test_read_data_large.c			\
	libarchive/test/test_read_extract.c			\
	libarchive/test/test_read_format_ar.c			\
	libarchive/test/test_read_format_cpio_bin.c		\
	libarchive/test/test_read_format_cpio_bin_Z.c		\
	libarchive/test/test_read_format_cpio_bin_bz2.c		\
	libarchive/test/test_read_format_cpio_bin_gz.c		\
	libarchive/test/test_read_format_cpio_odc.c		\
	libarchive/test/test_read_format_cpio_svr4_gzip.c	\
	libarchive/test/test_read_format_cpio_svr4c_Z.c		\
	libarchive/test/test_read_format_empty.c		\
	libarchive/test/test_read_format_gtar_gz.c		\
	libarchive/test/test_read_format_gtar_sparse.c		\
	libarchive/test/test_read_format_iso_gz.c		\
	libarchive/test/test_read_format_isorr_bz2.c		\
	libarchive/test/test_read_format_pax_bz2.c		\
	libarchive/test/test_read_format_tar.c			\
	libarchive/test/test_read_format_tbz.c			\
	libarchive/test/test_read_format_tgz.c			\
	libarchive/test/test_read_format_tz.c			\
	libarchive/test/test_read_format_zip.c			\
	libarchive/test/test_read_large.c			\
	libarchive/test/test_read_pax_truncated.c		\
	libarchive/test/test_read_position.c			\
	libarchive/test/test_read_truncated.c			\
	libarchive/test/test_tar_filenames.c			\
	libarchive/test/test_write_compress_program.c		\
	libarchive/test/test_write_disk.c			\
	libarchive/test/test_write_disk_perms.c			\
	libarchive/test/test_write_disk_secure.c		\
	libarchive/test/test_write_format_ar.c			\
	libarchive/test/test_write_format_cpio.c		\
	libarchive/test/test_write_format_cpio_empty.c		\
	libarchive/test/test_write_format_shar_empty.c		\
	libarchive/test/test_write_format_tar.c			\
	libarchive/test/test_write_format_tar_empty.c		\
	libarchive/test/test_write_open_memory.c

libarchive_test_CPPFLAGS=-I$(top_builddir)/libarchive -I$(top_builddir)/libarchive/test

# The "list.h" file just lists all of the tests defined in all of the sources.
# Building it automatically provides a sanity-check on libarchive_test_SOURCES
# above.
libarchive/test/list.h: Makefile
	cat $(top_srcdir)/libarchive/test/test_*.c | grep DEFINE_TEST > libarchive/test/list.h

#
#
# bsdtar source, docs, etc.
#
#

bsdtar_SOURCES=				\
		tar/bsdtar.c		\
		tar/bsdtar.h		\
		tar/bsdtar_platform.h	\
		tar/getdate.y		\
		tar/matching.c		\
		tar/read.c		\
		tar/tree.c		\
		tar/tree.h		\
		tar/util.c		\
		tar/write.c

bsdtar_DEPENDENCIES = libarchive.la		\
		libarchive/archive_entry.h	\
		libarchive/archive.h

if STATIC_BSDTAR
bsdtar_static=-static
else
bsdtar_static=
endif

bsdtar_LDADD= libarchive.la
bsdtar_CPPFLAGS=-I$(top_builddir)/libarchive
bsdtar_LDFLAGS= $(bsdtar_static) -I$(destdir)/libarchive

if BUILD_BSDTAR
bsdtar_dist_man_MANS=	tar/bsdtar.1
bsdtar_programs=bsdtar
else
bsdtar_dist_man_MANS=
bsdtar_programs=
endif

