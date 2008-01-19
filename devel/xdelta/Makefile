# $NetBSD: Makefile,v 1.32 2008/01/19 09:16:19 wiz Exp $
#

DISTNAME=		xdelta-1.1.1
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xcf.berkeley.edu/~jmacd/xdelta.html
COMMENT=		Enhanced diff that works on binary files

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
