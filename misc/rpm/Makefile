# $NetBSD: Makefile,v 1.11 1998/05/23 15:42:59 tv Exp $
#

DISTNAME=	rpm-2.4.12
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@NetBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:../../databases/gdbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
