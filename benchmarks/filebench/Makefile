# $NetBSD: Makefile,v 1.2 2012/09/11 22:37:12 asau Exp $

DISTNAME=	filebench-1.4.9.1
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=filebench/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://filebench.sf.net/
COMMENT=	File system and storage benchmark

GNU_CONFIGURE=		yes

USE_TOOLS=	lex
USE_TOOLS+=	aclocal autoconf automake

pre-configure:
	cd $(WRKSRC) && aclocal && automake && autoconf

post-install:
	cd $(WRKSRC) && $(INSTALL_DATA) README $(DESTDIR)$(PREFIX)/share/$(PKGBASE)/

.include "../../devel/libtecla/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
