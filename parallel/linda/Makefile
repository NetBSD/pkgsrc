# $NetBSD: Makefile,v 1.2 2002/09/10 16:06:48 wiz Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK_ONLY=	yes

.include "../../devel/glib2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
