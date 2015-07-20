# $NetBSD: Makefile,v 1.1.1.1 2015/07/20 20:19:16 asau Exp $

PKGNAME=	sql-workbench-117
DISTNAME=	Workbench-Build117
CATEGORIES=	databases
MASTER_SITES=	http://www.sql-workbench.net/
EXTRACT_SUFX=	.zip

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.sql-workbench.net/
COMMENT=	JDBC-based cross-platform SQL query tool.

EXTRACT_DIR=	$(WRKSRC)

USE_JAVA=	run
USE_JAVA2=	7

INSTALLATION_DIRS=	bin share/$(PKGBASE)

pre-extract:
	mkdir -p $(WRKSRC)

do-build:
	printf "#!/bin/sh\n$(PKG_JAVA_HOME)/bin/java -Dvisualvm.display.name=SQLWorkbench -Xmx512m -jar $(PREFIX)/share/$(PKGBASE)/sqlworkbench.jar \$${1:+\"\$$@\"}\n" > $(WRKDIR)/sqlworkbench.sh

do-install:
	cd $(WRKSRC) && pax -rwpm . $(DESTDIR)$(PREFIX)/share/$(PKGBASE)
	$(INSTALL_SCRIPT) $(WRKDIR)/sqlworkbench.sh $(DESTDIR)$(PREFIX)/bin/sqlworkbench

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
