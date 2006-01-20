# $NetBSD: Makefile,v 1.10 2006/01/20 16:15:52 jmmv Exp $
#

DISTNAME=	tdb-1.0.6
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

# both install tdbtool and tdbdump
CONFLICTS+=	samba-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
