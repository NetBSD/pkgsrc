# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:33 tv Exp $

PKGNAME=	swig-perl-${SWIG_VERSION}
PKGREVISION=	1
COMMENT=	Simplified Wrapper and Interface Generator, Perl runtime

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../swig-build/Makefile.common"

CONFIGURE_ARGS+=	--with-perl5=${PERL5}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
