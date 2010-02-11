# $NetBSD: Makefile,v 1.41 2010/02/11 02:18:34 asau Exp $
#

SQUEAK_VERSION=	3.11.3.2135	# see lang/squeak-vm

DISTNAME=	Squeak3.10.2-7179-basic
PKGNAME=	squeak-3.10.2.7179
CATEGORIES=	lang
MASTER_SITES=	http://ftp.squeak.org/3.10/
EXTRACT_SUFX=	.zip
DISTFILES=	$(DISTNAME)$(EXTRACT_SUFX) SqueakV39.sources.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://squeakvm.org/unix/
COMMENT=	Full Smalltalk 80 with portability to UN*X, Mac, and Windows

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS=	squeak-vm-[0-9]*:../../lang/squeak-vm

DIST_SUBDIR=	squeak
USE_TOOLS+=	gzip unzip
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/squeak/$(SQUEAK_VERSION)

SQUEAK_SOURCES=	SqueakV39.sources

post-extract:
	$(GZIP_CMD) -dc $(DISTDIR)/$(DIST_SUBDIR)/$(SQUEAK_SOURCES).gz > $(WRKDIR)/$(SQUEAK_SOURCES)

do-install:
	$(INSTALL_DATA) $(WRKDIR)/$(DISTNAME:=.image) $(DESTDIR)$(PREFIX)/lib/squeak/$(SQUEAK_VERSION)/
	$(INSTALL_DATA) $(WRKDIR)/$(DISTNAME:=.changes) $(DESTDIR)$(PREFIX)/lib/squeak/$(SQUEAK_VERSION)/
	$(INSTALL_DATA) $(WRKDIR)/$(SQUEAK_SOURCES) $(DESTDIR)$(PREFIX)/lib/squeak/$(SQUEAK_VERSION)/$(SQUEAK_SOURCES)

.include "../../mk/bsd.pkg.mk"
