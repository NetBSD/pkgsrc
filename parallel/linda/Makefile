# $NetBSD: Makefile,v 1.3 2002/10/08 22:33:40 jlam Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	1
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
