# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:18 jlam Exp $

PKGNAME=	swig-perl-${SWIG_VERSION}
PKGREVISION=	2
COMMENT=	Simplified Wrapper and Interface Generator, Perl runtime

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../swig-build/Makefile.common"

CONFIGURE_ARGS+=	--with-perl5=${PERL5}

BUILD_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
