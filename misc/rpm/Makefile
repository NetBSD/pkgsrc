# $NetBSD: Makefile,v 1.23 2000/11/01 16:00:40 itojun Exp $
#

DISTNAME=	rpm-2.5.4
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/ \
		ftp://ftp.gwdg.de/pub/linux/redhat/code/rpm/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.rpm.org/

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBINTL=	yes

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

post-install:
	${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
