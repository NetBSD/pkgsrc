# $NetBSD: Makefile,v 1.15 1998/08/20 15:17:15 tsarna Exp $
#

DISTNAME=	rpm-2.5.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/

CONFLICTS=	rpm-2.4.12

GNU_CONFIGURE=	yes

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
