# $NetBSD: Makefile,v 1.2 2003/07/17 21:29:08 grant Exp $
#

DISTNAME=	tdb-1.0.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
