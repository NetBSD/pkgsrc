# $NetBSD: Makefile,v 1.3 2016/03/09 17:41:06 asau Exp $

DISTNAME=	squirrelsql-3.7-standard
PKGNAME=	squirrelsql-3.7
CATEGORIES=	databases
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=squirrel-sql/)
EXTRACT_SUFX=	.zip

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.squirrelsql.org/
COMMENT=	A Java SQL client for any JDBC compliant database

SUBST_CLASSES+=			set-java set-base
SUBST_STAGE.set-java=		pre-configure
SUBST_MESSAGE.set-java=		Setting JAVA_HOME path.
SUBST_FILES.set-java=		squirrel-sql.sh
SUBST_SED.set-java=		-e 's,%JAVA_HOME,$(PKG_JAVA_HOME),g'

SUBST_STAGE.set-base=		pre-configure
SUBST_MESSAGE.set-base=		Setting package base path.
SUBST_FILES.set-base=		squirrel-sql.sh
SUBST_SED.set-base=		-e 's,@SQUIRREL_SQL_HOME@,$(PREFIX)/share/$(PKGBASE),g'

USE_JAVA=	run
USE_JAVA2=	6
NO_BUILD=	yes

INSTALLATION_DIRS=	bin share/$(PKGBASE)

do-install:
	cd $(WRKSRC) && pax -rwpm . $(DESTDIR)$(PREFIX)/share/$(PKGBASE)
	$(RM) -f $(DESTDIR)$(PREFIX)/share/$(PKGBASE)/squirrel-sql.sh.orig
	$(CHMOD) +x $(DESTDIR)$(PREFIX)/share/$(PKGBASE)/squirrel-sql.sh
	$(LN) -sf $(PREFIX)/share/$(PKGBASE)/squirrel-sql.sh $(DESTDIR)$(PREFIX)/bin/squirrel-sql

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
