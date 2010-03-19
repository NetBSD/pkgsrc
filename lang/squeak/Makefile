# $NetBSD: Makefile,v 1.42 2010/03/19 14:41:56 asau Exp $
#

SQUEAK_VERSION=	4.0
SQUEAK_SOURCES=	SqueakV40.sources

DISTNAME=	Squeak$(SQUEAK_VERSION)-basic
PKGNAME=	squeak-$(SQUEAK_VERSION)
CATEGORIES=	lang
MASTER_SITES=	http://ftp.squeak.org/$(SQUEAK_VERSION)/
EXTRACT_SUFX=	.zip
DISTFILES=	$(DISTNAME)$(EXTRACT_SUFX) $(SQUEAK_SOURCES).gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squeak.org/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows
LICENCE=	mit AND apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=	squeak-vm-[0-9]*:../../lang/squeak-vm

DIST_SUBDIR=	squeak
USE_TOOLS+=	gzip unzip
NO_BUILD=	yes

INSTALLATION_DIRS=	share/squeak/$(SQUEAK_VERSION)

post-extract:
	$(GZIP_CMD) -dc $(DISTDIR)/$(DIST_SUBDIR)/$(SQUEAK_SOURCES).gz > $(WRKDIR)/$(SQUEAK_SOURCES)

do-install:
	$(INSTALL_DATA) $(WRKDIR)/$(DISTNAME:=.image) $(DESTDIR)$(PREFIX)/share/squeak/$(SQUEAK_VERSION)/
	$(INSTALL_DATA) $(WRKDIR)/$(DISTNAME:=.changes) $(DESTDIR)$(PREFIX)/share/squeak/$(SQUEAK_VERSION)/
	$(INSTALL_DATA) $(WRKDIR)/$(SQUEAK_SOURCES) $(DESTDIR)$(PREFIX)/share/squeak/$(SQUEAK_VERSION)/$(SQUEAK_SOURCES)

.include "../../mk/bsd.pkg.mk"
