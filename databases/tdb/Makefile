# $NetBSD: Makefile,v 1.1.1.1 2002/11/29 19:19:12 jmmv Exp $
#

DISTNAME=	tdb-1.0.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
