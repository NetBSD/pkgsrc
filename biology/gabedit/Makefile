# $NetBSD: Makefile,v 1.4 2016/08/03 10:22:32 adam Exp $

PKGNAME=	gabedit-2.4.8
PKGREVISION=	1
DISTNAME=	GabeditSrc248
CATEGORIES=	biology
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=gabedit/)

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://gabedit.sourceforge.net/
COMMENT=	A Graphical User Interface to computational chemistry packages

USE_TOOLS=	gmake pkg-config

INSTALLATION_DIRS=	bin

# Skip check for example scripts:
CHECK_PORTABILITY_SKIP=	utils/Dalton/SGE/submitDalton \
			utils/Gamess/SGE/submitGamess

LDFLAGS.SunOS+=	-lsocket -lnsl

do-configure:
	cd $(WRKSRC) && cp platforms/CONFIG.unix CONFIG

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/gabedit $(DESTDIR)$(PREFIX)/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
