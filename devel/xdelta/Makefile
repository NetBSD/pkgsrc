# $NetBSD: Makefile,v 1.29 2005/05/22 20:07:55 jlam Exp $
#

DISTNAME=		xdelta-1.1.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xcf.berkeley.edu/~jmacd/xdelta.html
COMMENT=		Enhanced diff that works on binary files

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
INFO_FILES=		xdelta.info

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
