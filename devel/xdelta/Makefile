# $NetBSD: Makefile,v 1.18 2001/08/01 17:28:26 wiz Exp $
#

DISTNAME=		xdelta-1.1.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xcf.berkeley.edu/~jmacd/xdelta.html
COMMENT=		Enhanced diff that works on binary files

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

.include "../../devel/glib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
