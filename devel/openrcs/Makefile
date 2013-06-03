# $NetBSD: Makefile,v 1.1.1.1 2013/06/03 21:15:32 asau Exp $

DISTNAME=	openrcs-20110824192219
CATEGORIES=	devel
MASTER_SITES=	http://chl.be/openrcs/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://chl.be/openrcs/
COMMENT=	OpenRCS is RCS clone from OpenBSD project

WRKSRC=		$(WRKDIR)/openrcs

USE_TOOLS=	aclocal automake autoconf
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd $(WRKSRC) && $(CONFIG_SHELL) bootstrap

.include "../../mk/bsd.prefs.mk"
DISTDIR:=	$(PKGSRCDIR)/$(PKGPATH)	# override it!

.include "../../mk/bsd.pkg.mk"
