# $NetBSD: Makefile,v 1.10 1998/12/14 10:25:50 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	cu-sudo.v1.5.7p4
PKGNAME=	sudo-1.5.7p4
WRKSRC=		${WRKDIR}/sudo.v1.5.7p4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cs.colorado.edu/pub/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.courtesan.com/courtesan/products/sudo/

CONFLICTS=	sudo-1.5.3 sudo-1.5.4p1 sudo-1.5.6p2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-C2 --with-skey --with-nbsdops --disable-path-info

post-install:
	cd ${WRKSRC} ; ${CP} sample.sudoers ${PREFIX}/etc/sudoers.example

.include "../../mk/bsd.pkg.mk"
