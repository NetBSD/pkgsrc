# $NetBSD: Makefile,v 1.1.1.1 1999/11/17 14:48:18 drochner Exp $

DISTNAME=		cint5.14
PKGNAME=		cint-5.14
NO_WRKSUBDIR=		yes
CATEGORIES=		lang
MASTER_SITES=		ftp://root.cern.ch/root/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://root.cern.ch/root/Cint.html

do-build:
	cd $(WRKDIR); sh ./setup platform/netbsd

do-install:
	$(MKDIR) $(PREFIX)/cint
	$(INSTALL_PROGRAM) $(WRKDIR)/cint $(PREFIX)/cint
	$(INSTALL_PROGRAM) $(WRKDIR)/makecint $(PREFIX)/cint
	$(SED) "s;XXXPREFIXXXX;$(PREFIX);g" <$(FILESDIR)/cint.sh >$(PREFIX)/bin/cint
	$(CHMOD) +x $(PREFIX)/bin/cint
	$(LN) $(PREFIX)/bin/cint $(PREFIX)/bin/makecint
	$(INSTALL_DATA) $(WRKDIR)/MAKEINFO $(PREFIX)/cint
	$(CP) -r $(WRKDIR)/include $(WRKDIR)/stl $(PREFIX)/cint
	$(RM) $(PREFIX)/cint/include/G__*
	$(RM) $(PREFIX)/cint/include/Makeit $(PREFIX)/cint/include/make*
	$(MKDIR) $(PREFIX)/cint/lib
	$(CP) -r $(WRKDIR)/lib/prec_stl $(PREFIX)/cint/lib
	$(INSTALL_DATA) $(WRKDIR)/G__ci.h $(PREFIX)/cint

.include "../../mk/bsd.pkg.mk"
