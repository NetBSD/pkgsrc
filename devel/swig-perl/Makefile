# $NetBSD: Makefile,v 1.2 2004/03/07 23:20:35 minskim Exp $

PKGNAME=	swig-perl-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, Perl runtime

.include "../swig-build/Makefile.common"

CONFIGURE_ARGS+=	--with-perl5=${PERL5}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
