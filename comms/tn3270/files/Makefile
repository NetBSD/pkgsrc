#	$NetBSD: Makefile,v 1.3 2010/01/17 02:10:53 dholland Exp $

TOP=.
include $(TOP)/mk/setup.mk

all depend clean distclean:
	(cd tools && $(MAKE) $@)
	(cd tn3270 && $(MAKE) $@)
	(cd mset && $(MAKE) $@)

install:
	$(INSTALLDIR) $(DESTDIR)$(BINDIR)
	$(INSTALLDIR) $(DESTDIR)$(MAN1DIR)
	$(INSTALLDIR) $(DESTDIR)$(MAN5DIR)
	$(INSTALLDIR) $(DESTDIR)$(SHAREDIR)
	$(INSTALLBIN) tn3270/tn3270   $(DESTDIR)$(BINDIR)/tn3270
	$(INSTALLBIN) mset/mset       $(DESTDIR)$(BINDIR)/mset
	$(INSTALLMAN) tn3270/tn3270.1 $(DESTDIR)$(MAN1DIR)/tn3270.1
	$(INSTALLMAN) mset/mset.1     $(DESTDIR)$(MAN1DIR)/mset.1
	$(INSTALLMAN) mset/map3270.5  $(DESTDIR)$(MAN5DIR)/map3270.5
	$(INSTALLFILE) mset/map3270   $(DESTDIR)$(SHAREDIR)/map3270
