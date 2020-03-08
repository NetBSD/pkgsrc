# $NetBSD: Makefile,v 1.26 2020/03/08 16:51:02 wiz Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	11
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
