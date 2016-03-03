# $NetBSD: Makefile,v 1.2 2016/03/03 17:43:45 asau Exp $

PKGNAME=	sql-workbench-119
DISTNAME=	Workbench-Build119
CATEGORIES=	databases
MASTER_SITES=	http://www.sql-workbench.net/
EXTRACT_SUFX=	.zip

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.sql-workbench.net/
COMMENT=	JDBC-based cross-platform SQL query tool.

EXTRACT_DIR=	$(WRKSRC)

USE_JAVA=	run
USE_JAVA2=	8
PKG_JVMS_ACCEPTED=  sun-jdk8 openjdk8

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
