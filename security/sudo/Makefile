# $NetBSD: Makefile,v 1.8 1998/09/28 13:10:07 frueauf Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	cu-sudo.v1.5.6p2
PKGNAME=	sudo-1.5.6p2
CATEGORIES=	security
MASTER_SITES=	ftp://freestuff.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	packages@netbsd.org

CONFLICTS=	sudo-1.5.3 sudo-1.5.4p1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-C2 --with-skey --with-nbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.6p2

post-install:
	cd ${WRKSRC} ; ${CP} sample.sudoers ${PREFIX}/etc/sudoers.example

.include "../../mk/bsd.pkg.mk"
