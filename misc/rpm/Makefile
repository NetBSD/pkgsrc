# $NetBSD: Makefile,v 1.10 1998/04/24 09:20:36 agc Exp $
#

DISTNAME=	rpm-2.4.12
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@NetBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:../../databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=${MACHINE_ARCH}--netbsd
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
