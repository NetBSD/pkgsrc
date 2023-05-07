## $NetBSD: Makefile.am,v 1.2 2023/05/07 19:13:27 wiz Exp $

noinst_LTLIBRARIES = libedit.la

libedit_la_SOURCES = \
	chared.c \
	chartype.c \
	common.c \
	el.c \
	eln.c \
	emacs.c \
	filecomplete.c \
	hist.c \
	history.c \
	historyn.c \
	keymacro.c \
	literal.c \
	map.c \
	parse.c \
	prompt.c \
	read.c \
	readline.c \
	refresh.c \
	search.c \
	sig.c \
	terminal.c \
	tokenizer.c \
	tokenizern.c \
	tty.c \
	vi.c

libedit_la_CPPFLAGS = \
	-I. \
	-I$(srcdir) \
	-I$(top_srcdir)/libnetbsd \
	-I$(top_srcdir) \
	-I$(top_builddir)

libedit_la_LIBADD = \
	$(top_builddir)/libnetbsd/libnetbsd.la

generated_files = \
	common.h \
	emacs.h \
	fcns.h \
	func.h \
	help.h\
	vi.h

nodist_libedit_la_SOURCES = \
	$(generated_files)

BUILT_SOURCES = \
	$(generated_files)

CLEANFILES = \
	$(generated_files)

MAKELIST=AWK=$(AWK) $(SHELL) $(srcdir)/makelist


vi.h: vi.c
	$(AM_V_GEN)$(MAKELIST) -h $(srcdir)/vi.c > $@

emacs.h: emacs.c
	$(AM_V_GEN)$(MAKELIST) -h $(srcdir)/emacs.c > $@

common.h: common.c
	$(AM_V_GEN)$(MAKELIST) -h $(srcdir)/common.c > $@

fcns.h: vi.h emacs.h common.h
	$(AM_V_GEN)$(MAKELIST) -fh vi.h emacs.h common.h > $@

func.h: vi.h emacs.h common.h
	$(AM_V_GEN)$(MAKELIST) -fc vi.h emacs.h common.h > $@

help.h: vi.c emacs.c common.c
	$(AM_V_GEN)$(MAKELIST) -bh $(srcdir)/vi.c $(srcdir)/emacs.c $(srcdir)/common.c > $@

EXTRA_DIST = \
	TEST/rl1.c \
	TEST/tc1.c \
	TEST/test_filecompletion.c \
	TEST/wtc1.c \
	chared.h \
	chartype.h \
	config.h \
	editline.3 \
	editline.7 \
	editrc.5 \
	el.h \
	filecomplete.h \
	hist.h \
	histedit.h \
	keymacro.h \
	literal.h \
	makelist \
	map.h \
	parse.h \
	prompt.h \
	read.h \
	readline/readline.h \
	refresh.h \
	search.h \
	sig.h \
	sys.h \
	terminal.h \
	tty.h
