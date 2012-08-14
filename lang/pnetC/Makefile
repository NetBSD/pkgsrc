# $NetBSD: Makefile,v 1.13 2012/08/14 17:07:57 asau Exp $
#

DISTNAME=	pnetC-0.6.6
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=dotgnu/pnet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dotgnu.org/
COMMENT=	C language binding for DotGNU Portable .NET

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../lang/pnet/buildlink3.mk"
.include "../../lang/pnetlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
