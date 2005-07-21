# $NetBSD: Makefile,v 1.7 2005/07/21 16:29:55 wiz Exp $

DISTNAME=		jigdo-0.7.1
CATEGORIES=		net
MASTER_SITES=		http://atterer.net/jigdo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://atterer.net/jigdo/
COMMENT=		Tool to ease downloading of large files from the Internet

CONFIGURE_ARGS+=	--without-libdb
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

#.include "../../databases/db3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
