# $NetBSD: Makefile,v 1.5 2003/06/02 01:21:09 jschauma Exp $

DISTNAME=	gnats-3.113.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/sourceware/gnats/snapshots/ \
		ftp://mirrors.rcn.net/pub/sourceware/gnats/snapshots/ \
		ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/gnats/snapshots/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://sourceware.cygnus.com/gnats/
COMMENT=	Cygnus GNATS bug tracking system

BUILD_DEPENDS+=	m4-*:../../devel/m4

USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	yes
USE_BISON=	yes
TEXINFO_OVERRIDE=	YES

CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-full-gnats \
		--with-release-based

GNATS_HOME=	${PREFIX}/share/gnats/gnats-db
PKG_USERS=	gnats:daemon::GNATS\\ database\\ owner:${GNATS_HOME}:/bin/sh
MAKE_DIRS=		${PREFIX}/share/gnats
OWN_DIRS_PERMS=		${GNATS_HOME} gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-queue gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/pending gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-adm gnats daemon 755
OWN_DIRS_PERMS+=	${GNATS_HOME}/gnats-adm/locks gnats daemon 755

MESSAGE_SUBST+=		PREFIX="${PREFIX}"

# this stops the configuration program from pulling installation
# information in from the standard NetBSD send-pr program
CONFIGURE_ENV=	SEND_PR=/dev/null

# the gnats distribution comes with a lot of baggage we don't want to install
# just install gnats
INSTALL_TARGET=	install-gnats install-send-pr

post-build:
	(cd ${WRKSRC}/gnats;   ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info)
	(cd ${WRKSRC}/send-pr; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info)

post-install:
	(cd ${WRKSRC}/gnats;   ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-info)
	(cd ${WRKSRC}/send-pr; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-info)
	${INSTALL_INFO} ${PREFIX}/info/gnats.info   ${PREFIX}/info/dir
	${INSTALL_INFO} ${PREFIX}/info/send-pr.info ${PREFIX}/info/dir

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
