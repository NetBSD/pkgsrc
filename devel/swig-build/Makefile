# $NetBSD: Makefile,v 1.1.1.1 2003/05/25 08:52:37 epg Exp $

PKGNAME=	swig-build-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, base build files

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-guile
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-ocaml
CONFIGURE_ARGS+=	--without-perl5
CONFIGURE_ARGS+=	--without-php4
CONFIGURE_ARGS+=	--without-pike
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-ruby
CONFIGURE_ARGS+=	--without-tcl

.include "../../mk/bsd.pkg.mk"
