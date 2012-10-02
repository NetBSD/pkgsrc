# $NetBSD: Makefile,v 1.15 2012/10/02 21:25:54 asau Exp $
#

DISTNAME=	tdb-1.0.6
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

# both install tdbtool and tdbdump
CONFLICTS+=	samba-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
