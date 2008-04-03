# $NetBSD: Makefile,v 1.5 2008/04/03 08:42:25 joerg Exp $
#

DISTNAME=		ming-0.3.0
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ming/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Create SWF (Macromedia Flash) files with this library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex
GNU_CONFIGURE=		yes

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR:Q}${PREFIX:Q}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
