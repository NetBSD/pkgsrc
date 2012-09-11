# $NetBSD: Makefile,v 1.23 2012/09/11 20:36:17 asau Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	9
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
