# $NetBSD: Makefile,v 1.1.1.1 2007/11/13 18:02:15 jlam Exp $

DISTNAME=	cone-0.73
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=courier/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.courier-mta.org/cone/
COMMENT=	console newsreader and emailer

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
GCC_REQD+=		3.0	# need Standard C++ Library

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-certdb

EGDIR=			${PREFIX}/share/examples/cone
INSTALL_AM_MAKEFLAGS+=	sysconfdir=${EGDIR:Q}
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} AM_MAKEFLAGS=${INSTALL_AM_MAKEFLAGS:Q}

CONF_FILES=		${EGDIR}/cone.dist ${PKG_SYSCONFDIR}/cone

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
