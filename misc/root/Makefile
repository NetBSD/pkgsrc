# $NetBSD: Makefile,v 1.1.1.1 1999/11/17 16:17:03 drochner Exp $

DISTNAME=		root_v2.23.08.source
PKGNAME=		root-2.23
NO_WRKSUBDIR=		yes
CATEGORIES=		misc
MASTER_SITES=		ftp://root.cern.ch/root/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://root.cern.ch/

BUILD_DEPENDS+= cint:../../lang/cint
DEPENDS+= xpm-*:../../graphics/xpm

USE_GMAKE= yes
ALL_TARGET= netbsd
MAKE_ENV= LD_LIBRARY_PATH=$(WRKDIR)/lib ROOTSYS=$(WRKDIR)

do-configure:
	$(CP) $(FILESDIR)/Makefile.netbsd $(WRKDIR)/src
	$(MKDIR) $(WRKDIR)/bin
	$(MKDIR) $(WRKDIR)/lib
	$(CP) $(PREFIX)/cint/MAKEINFO $(WRKDIR)/cint
	$(CP) $(PREFIX)/cint/include/iosenum.h $(WRKDIR)/cint/include

do-install:
	$(MKDIR) $(PREFIX)/root
	$(MKDIR) $(PREFIX)/root/include
	(cd $(WRKDIR)/src; $(CP) *.h MAIN_rmain.cxx $(PREFIX)/root/include)
	(cd $(WRKDIR); tar cf - lib bin cint)|(cd $(PREFIX)/root;tar xf -)
	$(SED) "s;XXXPREFIXXXX;$(PREFIX);g" <$(FILESDIR)/root.sh >$(PREFIX)/bin/root
	$(CHMOD) +x $(PREFIX)/bin/root

.include "../../mk/bsd.pkg.mk"
