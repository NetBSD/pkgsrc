# $NetBSD: Makefile,v 1.7 1998/07/01 19:09:42 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	cu-sudo.v1.5.4p1
PKGNAME=	sudo-1.5.4p1
CATEGORIES=	security
MASTER_SITES=	ftp://freestuff.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

CONFLICTS=	sudo-1.5.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-C2 --with-skey --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.4p1

post-install:
	cd ${WRKSRC} ; ${CP} sample.sudoers ${PREFIX}/etc/sudoers.example

.include "../../mk/bsd.pkg.mk"
