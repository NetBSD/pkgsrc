# $NetBSD: Makefile,v 1.23 2003/06/25 12:10:42 seb Exp $
#

DISTNAME=		xdelta-1.1.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xcf.berkeley.edu/~jmacd/xdelta.html
COMMENT=		Enhanced diff that works on binary files

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_NEW_TEXINFO=	YES
INFO_FILES=		xdelta.info

.include "../../devel/glib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
