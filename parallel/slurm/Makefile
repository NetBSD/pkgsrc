# $NetBSD: Makefile,v 1.5 2012/09/11 20:36:18 asau Exp $

DISTNAME=	slurm-2.4.1
CATEGORIES=	parallel
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.schedmd.com/
COMMENT=	Simple Linux Utility for Resource Management

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS=	perl pkg-config
USE_LIBTOOL=	yes

# Fix installation:
CONFIGURE_ARGS+=	--htmldir=$(PREFIX)/share/doc/$(PKGNAME_NOREV)/html

REPLACE_PYTHON=	doc/html/shtml2html.py

PKG_GROUPS=		slurm
PKG_USERS=		slurm:slurm

PKG_GECOS.slurm=	SLURM user
PKG_SHELL.slurm=	$(NOLOGIN)

post-install:
	$(INSTALL_DATA_DIR) $(DESTDIR)$(PREFIX)/share/examples/$(PKGBASE)
	$(INSTALL_DATA) $(WRKSRC)/etc/* $(DESTDIR)$(PREFIX)/share/examples/$(PKGBASE)/

.include "../../lang/python/tool.mk"

CONFIGURE_ARGS+=	--with-munge=$(BUILDLINK_PREFIX.munge:Q)
.include "../../security/munge/buildlink3.mk" # optional
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
