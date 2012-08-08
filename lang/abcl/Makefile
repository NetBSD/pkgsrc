# $NetBSD: Makefile,v 1.1.1.1 2012/08/08 20:24:44 asau Exp $

DISTNAME=	abcl-src-1.0.1
PKGNAME=	$(DISTNAME:C/-src//)
CATEGORIES=	lang
MASTER_SITES=	http://common-lisp.net/project/armedbear/releases/$(PKGVERSION_NOREV)/

MAINTAINER=	asau@NetBSD.org
HOMEPAGE=	http://common-lisp.net/project/armedbear/
COMMENT=	Armed Bear Common Lisp

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS=	apache-ant>=1.7.1:../../devel/apache-ant

INSTALLATION_DIRS=	bin lib/abcl

do-build:
	$(RUN)$(_ULIMIT_CMD) cd $(WRKSRC) && \
	  $(PKGSRC_SETENV) $(MAKE_ENV) \
	    ant -nouserlib -Dabcl.runtime.jar.path=$(PREFIX)/lib/abcl/abcl.jar

do-install:
	$(INSTALL_SCRIPT) $(WRKSRC)/abcl $(DESTDIR)$(PREFIX)/bin
	$(INSTALL_DATA) $(WRKSRC)/dist/abcl.jar $(DESTDIR)$(PREFIX)/lib/abcl
	$(INSTALL_DATA) $(WRKSRC)/dist/abcl-contrib.jar $(DESTDIR)$(PREFIX)/lib/abcl

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
