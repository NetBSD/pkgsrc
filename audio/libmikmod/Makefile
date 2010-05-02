# $NetBSD: Makefile,v 1.48 2010/05/02 11:42:17 wiz Exp $

DISTNAME=		libmikmod-3.1.12
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mikmod/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mikmod.raphnet.net/
COMMENT=		MikMod Sound Library
LICENSE=		gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

CONFIGURE_ARGS+=	--disable-threads

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
