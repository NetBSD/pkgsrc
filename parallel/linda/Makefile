# $NetBSD: Makefile,v 1.4 2002/12/24 06:10:20 wiz Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linda/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/linda/
COMMENT=	Parallel distributed database environment

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
