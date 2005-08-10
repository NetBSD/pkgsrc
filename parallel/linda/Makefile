# $NetBSD: Makefile,v 1.15 2005/08/10 20:56:22 jlam Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	5
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
