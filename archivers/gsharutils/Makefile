# $NetBSD: Makefile,v 1.4 2000/08/19 23:37:07 christos Exp $

DISTNAME=	sharutils-4.2.1
PKGNAME=	g${DISTNAME}
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=sharutils/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/sharutils/sharutils.html

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode --with-gnu-gettext
INSTALL_TARGET= install install-man
INFO_FILES=	remsync.info sharutils.info

post-patch:
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/po/sharutils.pot

.include "../../mk/bsd.pkg.mk"
