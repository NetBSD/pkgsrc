# $NetBSD: Makefile,v 1.16 2001/02/16 14:39:06 wiz Exp $
#

DISTNAME=		xdelta-0.22
CATEGORIES=		devel
MASTER_SITES=		ftp://www.xcf.berkeley.edu/pub/xdelta/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://scam.XCF.Berkeley.EDU/~jmacd/xdelta.html
COMMENT=		Enhanced diff that works on binary files

DEPENDS+=		glib-1.2.*:../../devel/glib
DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		yes
LDFLAGS+=		"-L${LOCALBASE}/lib"
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
