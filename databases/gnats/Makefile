# $NetBSD: Makefile,v 1.11 2004/01/22 08:02:15 grant Exp $

DISTNAME=	gnats-3.113.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU=gnats/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnats/
COMMENT=	Cygnus GNATS bug tracking system

BUILD_DEPENDS+=	m4-*:../../devel/m4

USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_BISON=	yes

USE_MAKEINFO=	YES
INFO_FILES=	gnats.info send-pr.info

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

PLIST_SRC=	${WRKSRC}/.PLIST

post-build:
	(cd ${WRKSRC}/gnats;   ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info)
	(cd ${WRKSRC}/send-pr; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} info)

post-install:
	(cd ${WRKSRC}/gnats;   ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-info)
	(cd ${WRKSRC}/send-pr; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-info)
	${LS} ${PREFIX}/share/gnats/dist/send-pr.info* | \
		${SED} -e 's,^${PREFIX}/,,' > ${PLIST_SRC}
	${CAT} ${.CURDIR}/PLIST >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
