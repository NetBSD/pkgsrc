# $NetBSD: Makefile,v 1.12 2004/12/14 20:34:42 minskim Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	5
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=		YES
USE_LIBTOOL=		# defined

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
