# $NetBSD: Makefile,v 1.3 2004/01/22 08:02:16 grant Exp $
#

DISTNAME=	tdb-1.0.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
