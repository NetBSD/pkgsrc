# $NetBSD: Makefile,v 1.8 2005/12/05 23:55:06 rillig Exp $

PKGNAME=	swig-perl-${SWIG_VERSION}
PKGREVISION=	2
COMMENT=	Simplified Wrapper and Interface Generator, Perl runtime

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../devel/swig-build/Makefile.common"

CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}

BUILD_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
