# $NetBSD: Makefile,v 1.5 2003/05/02 11:56:14 wiz Exp $
#

DISTNAME=	linda-0.1.1
PKGREVISION=	3
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
