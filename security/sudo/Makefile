# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:47 agc Exp $
# FreeBSD Id: Makefile,v 1.9 1997/11/12 03:24:41 obrien Exp
#

DISTNAME=	cu-sudo.v1.5.3
PKGNAME=	sudo-1.5.3
CATEGORIES=	security
MASTER_SITES=	ftp://freestuff.cs.colorado.edu/pub/sysadmin/sudo/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	erich@rrnet.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-C2 --with-skey --with-fbsdops
WRKSRC=		${WRKDIR}/sudo.v1.5.3
MAN5=		sudoers.5
MAN8=		sudo.8 visudo.8

post-install:
	cd ${WRKSRC} ; ${CP} sample.sudoers ${PREFIX}/etc/sudoers.example

.include "../../mk/bsd.pkg.mk"
