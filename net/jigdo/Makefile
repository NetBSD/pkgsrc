# $NetBSD: Makefile,v 1.35 2012/10/02 17:11:47 tron Exp $

DISTNAME=		jigdo-0.7.3
PKGREVISION=		15
CATEGORIES=		net
MASTER_SITES=		http://atterer.org/sites/atterer/files/2009-08/jigdo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://atterer.org/jigdo/
COMMENT=		Tool to ease downloading of large files from the Internet

DEPENDS+=		wget-[0-9]*:../../net/wget

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-libdb
BROKEN_GETTEXT_DETECTION=	yes

#.include "../../databases/db3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
