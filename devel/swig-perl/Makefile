# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 15:11:23 epg Exp $

PKGNAME=	swig-perl-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, Perl runtime

.include "../swig-build/Makefile.common"

CONFIGURE_ARGS+=	--with-perl5=${PERL5}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
