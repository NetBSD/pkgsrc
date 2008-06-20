# $NetBSD: Makefile,v 1.14 2008/06/20 01:09:11 joerg Exp $
#

DISTNAME=	tdb-1.0.6
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/tdb/
COMMENT=	Small database system which uses files to store data

PKG_DESTDIR_SUPPORT=	user-destdir

# both install tdbtool and tdbdump
CONFLICTS+=	samba-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
