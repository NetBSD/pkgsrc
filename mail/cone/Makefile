# $NetBSD: Makefile,v 1.30 2018/08/22 09:45:23 wiz Exp $

DISTNAME=	cone-0.90
PKGREVISION=	17
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.courier-mta.org/cone/
COMMENT=	Console newsreader and emailer
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl true
GCC_REQD+=		3.0	# need Standard C++ Library

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-certdb=${SSLCERTS}

# Cone doesn't really need the openssl or c_rehash binaries, but the
# rootcerts/configure script is written poorly and directly overrides
# variables that were meant for the builder to use.  Fix that by
# overriding the special ac_cv_* configure cache variables as a last
# resort.
CONFIGURE_ENV+=		ac_cv_path_OPENSSL=${TOOLS_TRUE}
CONFIGURE_ENV+=		ac_cv_path_REHASH=${TOOLS_TRUE}

EGDIR=			${PREFIX}/share/examples/cone
INSTALL_AM_MAKEFLAGS+=	sysconfdir=${EGDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

CONF_FILES=		${EGDIR}/cone.dist ${PKG_SYSCONFDIR}/cone

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
