# $NetBSD: Makefile,v 1.51 2016/12/19 15:37:50 asau Exp $

SQUEAK_VERSION=	4.5
IMAGE_VERSION=  13680
SQUEAK_SOURCES=	SqueakV41.sources

DISTNAME=	Squeak$(SQUEAK_VERSION)-$(IMAGE_VERSION)
PKGNAME=	squeak-$(SQUEAK_VERSION)
CATEGORIES=	lang
MASTER_SITES=	http://ftp.squeak.org/$(SQUEAK_VERSION)/
EXTRACT_SUFX=	.zip
DISTFILES=	${DEFAULT_DISTFILES} $(SQUEAK_SOURCES).gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squeak.org/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows
LICENSE=	mit AND apache-2.0

DEPENDS=	squeak-vm-[0-9]*:../../lang/squeak-vm

DIST_SUBDIR=	squeak
USE_TOOLS+=	gzip unzip
NO_BUILD=	yes
PLIST_SUBST+=	IMAGE_VERSION=$(IMAGE_VERSION)

INSTALLATION_DIRS=	share/squeak/$(SQUEAK_VERSION)

post-extract:
	$(GZIP_CMD) -dc $(DISTDIR)/$(DIST_SUBDIR)/$(SQUEAK_SOURCES).gz > $(WRKDIR)/$(SQUEAK_SOURCES)

do-install:
	$(INSTALL_DATA) $(WRKDIR)/$(DISTNAME:=.image) $(DESTDIR)$(PREFIX)/share/squeak/$(SQUEAK_VERSION)/
	$(INSTALL_DATA) $(WRKDIR)/$(DISTNAME:=.changes) $(DESTDIR)$(PREFIX)/share/squeak/$(SQUEAK_VERSION)/
	$(INSTALL_DATA) $(WRKDIR)/$(SQUEAK_SOURCES) $(DESTDIR)$(PREFIX)/share/squeak/$(SQUEAK_VERSION)/$(SQUEAK_SOURCES)

.include "../../mk/bsd.pkg.mk"
