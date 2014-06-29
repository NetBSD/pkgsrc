# $NetBSD: Makefile,v 1.2 2014/06/29 06:27:07 dholland Exp $

DISTNAME=	openrcs-20110824192219
CATEGORIES=	devel
MASTER_SITES=	http://chl.be/openrcs/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://chl.be/openrcs/
COMMENT=	OpenRCS is RCS clone from OpenBSD project

WRKSRC=		$(WRKDIR)/openrcs

USE_TOOLS=	aclocal automake autoconf yacc
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd $(WRKSRC) && $(CONFIG_SHELL) bootstrap

.include "../../mk/bsd.pkg.mk"
