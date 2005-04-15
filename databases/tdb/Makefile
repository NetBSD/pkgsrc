# $NetBSD: Makefile,v 1.8 2005/04/15 11:45:16 wiz Exp $
#

DISTNAME=	tdb-1.0.6
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

# both install tdbtool and tdbdump
CONFLICTS+=	samba-[0-9]*

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
