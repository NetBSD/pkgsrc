# $NetBSD: Makefile,v 1.18 1999/02/17 08:13:27 tron Exp $
#

DISTNAME=	rpm-2.5.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/

BUILD_DEPENDS+=	${LOCALBASE}/lib/libintl.a:../../devel/gettext

CONFLICTS=	rpm-2.4.12 rpm-2.5.1

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include "../../mk/bsd.pkg.mk"
