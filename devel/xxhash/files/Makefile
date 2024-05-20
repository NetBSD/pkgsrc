# $NetBSD: Makefile,v 1.3 2024/05/20 11:45:55 nia Exp $

LIBTOOL?=		libtool
MANDIR?=		man

MAJOR!=			printf '%s\n' "$(PKGVERSION_NOREV)" | cut -d. -f1

XXHSUM_SRC_DIR=		cli

XXHSUM_SPLIT_OBJS=	$(XXHSUM_SRC_DIR)/xxhsum.lo \
			$(XXHSUM_SRC_DIR)/xsum_os_specific.lo \
			$(XXHSUM_SRC_DIR)/xsum_output.lo \
			$(XXHSUM_SRC_DIR)/xsum_sanity_check.lo \
			$(XXHSUM_SRC_DIR)/xsum_bench.lo

.SUFFIXES: .lo

.c.lo:
	$(LIBTOOL) --quiet --tag=CC --mode=compile $(CC) $(CFLAGS) -c $< -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: libxxhash.la libxxhash.pc xxh32sum xxh64sum xxh128sum \
	xxh32sum.1 xxh64sum.1 xxh128sum.1

xxh32sum xxh64sum xxh128sum: xxhsum
	ln -sf xxhsum $@

xxh32sum.1 xxh64sum.1 xxh128sum.1: $(XXHSUM_SRC_DIR)/xxhsum.1
	ln -sf $(XXHSUM_SRC_DIR)/xxhsum.1 $@

libxxhash.la: xxhash.lo
	$(LIBTOOL) --quiet --tag=CC --mode=link \
		$(CC) $(LDFLAGS) -rpath $(PREFIX)/lib -version-info $(MAJOR):0 -o $@ xxhash.lo

xxhsum: xxhash.lo $(XXHSUM_SPLIT_OBJS)
	$(LIBTOOL) --quiet --tag=CC --mode=link \
		$(CC) $(CFLAGS) $(LDFLAGS) -o $@ xxhash.lo $(XXHSUM_SPLIT_OBJS)

libxxhash.pc: libxxhash.pc.in
	sed	-e "s,@PREFIX@,$(PREFIX),g" \
		-e "s,@EXECPREFIX@,$(PREFIX)/bin,g" \
		-e "s,@INCLUDEDIR@,$(PREFIX)/include,g" \
		-e "s,@LIBDIR@,$(PREFIX)/lib,g" \
		-e "s,@VERSION@,$(PKGVERSION_NOREV),g" \
		libxxhash.pc.in > libxxhash.pc

install:
	mkdir -p $(DESTDIR)$(PREFIX)/$(MANDIR)/man1
	$(BSD_INSTALL_MAN) $(XXHSUM_SRC_DIR)/xxhsum.1 $(DESTDIR)$(PREFIX)/$(MANDIR)/man1
	$(BSD_INSTALL_MAN) xxh32sum.1 $(DESTDIR)$(PREFIX)/$(MANDIR)/man1
	$(BSD_INSTALL_MAN) xxh64sum.1 $(DESTDIR)$(PREFIX)/$(MANDIR)/man1
	$(BSD_INSTALL_MAN) xxh128sum.1 $(DESTDIR)$(PREFIX)/$(MANDIR)/man1
	mkdir -p $(DESTDIR)$(PREFIX)/lib/pkgconfig
	$(LIBTOOL) --mode=install $(BSD_INSTALL_DATA) libxxhash.pc \
		$(DESTDIR)$(PREFIX)/lib/pkgconfig
	$(LIBTOOL) --mode=install $(BSD_INSTALL_LIB) libxxhash.la \
		$(DESTDIR)$(PREFIX)/lib
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	$(LIBTOOL) --mode=install \
		$(BSD_INSTALL_PROGRAM) xxhsum $(DESTDIR)$(PREFIX)/bin
	$(BSD_INSTALL_PROGRAM) xxh32sum $(DESTDIR)$(PREFIX)/bin
	$(BSD_INSTALL_PROGRAM) xxh64sum $(DESTDIR)$(PREFIX)/bin
	$(BSD_INSTALL_PROGRAM) xxh128sum $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/include
	$(BSD_INSTALL_DATA) xxhash.h $(DESTDIR)$(PREFIX)/include
	$(BSD_INSTALL_DATA) xxh3.h $(DESTDIR)$(PREFIX)/include

clean:
	rm -f $(XXHSUM_SPLIT_OBJS)
	rm -f xxhash.lo xxhash.o
	rm -f libxxhash.lo libxxhash.o
	rm -f xxhsum xxh32sum xxh64sum xxh128sum
