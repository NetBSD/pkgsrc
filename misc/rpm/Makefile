# $NetBSD: Makefile,v 1.19 1999/02/19 01:01:06 tv Exp $
#

DISTNAME=	rpm-2.5.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/

BUILD_DEPENDS+=	${LOCALBASE}/lib/libintl.a:../../devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
