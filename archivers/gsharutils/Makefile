# $NetBSD: Makefile,v 1.5 2000/11/02 02:35:14 itojun Exp $

DISTNAME=	sharutils-4.2.1
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext

USE_LIBINTL=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode
INSTALL_TARGET= install install-man
INFO_FILES=	remsync.info sharutils.info

post-patch:
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/po/sharutils.pot

.include "../../mk/bsd.pkg.mk"
