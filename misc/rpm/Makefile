# $NetBSD: Makefile,v 1.12 1998/06/22 12:52:34 agc Exp $
#

DISTNAME=	rpm-2.4.12
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@NetBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:../../databases/gdbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
