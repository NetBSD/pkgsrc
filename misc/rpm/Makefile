# $NetBSD: Makefile,v 1.13 1998/07/10 05:25:45 mycroft Exp $
#

DISTNAME=	rpm-2.5.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@NetBSD.ORG

CONFLICTS=	rpm-2.4.12

DEPENDS=	gdbm-1.7.3:../../databases/gdbm

GNU_CONFIGURE=	yes

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
