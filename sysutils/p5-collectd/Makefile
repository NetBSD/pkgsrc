# $NetBSD: Makefile,v 1.5 2017/06/05 14:24:38 ryoon Exp $

PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
COLLECTD_PACKAGE=	perl

COMMENT=		Statistics collection daemon - perl plugin

.include "../../sysutils/collectd/Makefile.common"

USE_TOOLS+=		perl

PERL5_CONFIGURE=	no
PERL5_PACKLIST+=	auto/Collectd/.packlist

CONFIGURE_ARGS+=	--with-libperl=${BUILDLINK_PREFIX.perl}
CONFIGURE_ARGS+=	--with-perl-bindings=${MAKE_PARAMS:Q}

post-build:
	cd ${WRKSRC}/bindings && ${BUILD_MAKE_CMD} perl

do-install:
	cd ${WRKSRC}/src && ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV}		\
	  ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} ${INSTALL_TARGET}
	cd ${WRKSRC}/bindings && ${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV}	\
	  ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
