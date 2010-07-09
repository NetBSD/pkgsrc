# $NetBSD: module.mk,v 1.1 2010/07/09 18:08:05 asau Exp $

# Used variables:
# CLISP_MODULE - name of module and subdirectory in "modules"

CLISP_VERSION=		2.49
DISTNAME=		clisp-$(CLISP_VERSION)

# Sparc64 has assembler code problems, see
# http://sourceforge.net/tracker/index.php?func=detail&aid=952681&group_id=1355&atid=101355
NOT_FOR_PLATFORM=	*-*-sparc64
NOT_FOR_PLATFORM+=	*-*-arm

PKG_INSTALLATION_TYPES= overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir


CONFIGURE_DIRS=		modules/$(CLISP_MODULE)
GNU_CONFIGURE=		YES
BUILD_TARGET=		clisp-module	# converting to "all"

CONFIGURE_ENV+=		ac_install_sh="install -c"
CONFIGURE_ENV+=		ac_aux_dir=$(PREFIX)/lib/clisp/build-aux/
#TEST_TARGET=		check mod-check

INSTALLATION_DIRS=	lib/clisp

do-install:
	$(INSTALL_DATA_DIR) $(DESTDIR)$(PREFIX)/lib/clisp/dynmod
	cd $(WRKSRC)/modules;	\
	$(SETENV) DESTDIR=$(DESTDIR:Q) sh $(LOCALBASE)/bin/clisp-link install $(CLISP_MODULE)

.include "../../lang/clisp/buildlink3.mk"
