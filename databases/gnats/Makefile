# $NetBSD: Makefile,v 1.2 2002/02/18 15:14:06 seb Exp $

DISTNAME=	gnats-3.113.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/sourceware/gnats/snapshots/ \
		ftp://mirrors.rcn.net/pub/sourceware/gnats/snapshots/ \
		ftp://sunsite.org.uk/Mirrors/sourceware.cygnus.com/pub/gnats/snapshots/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceware.cygnus.com/gnats/
COMMENT=	Cygnus GNATS bug tracking system

BUILD_DEPENDS+=	m4-*:../../devel/m4

.if exists(/usr/sbin/user)
ADDUSER=	/usr/sbin/useradd
ADDGROUP=	/usr/sbin/groupadd
.else
DEPENDS+=	user>=20000313:../../sysutils/user
ADDUSER=	${LOCALBASE}/sbin/useradd
ADDGROUP=	${LOCALBASE}/sbin/groupadd
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir=${PREFIX}/share/emacs/site-lisp \
		--with-full-gnats \
		--with-release-based
USE_GMAKE=	yes
USE_BISON=	yes
TEXINFO_OVERRIDE=	YES

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

INSTALL_SUBST+=		PREFIX="${PREFIX}"
INSTALL_SUBST+=		USER="gnats"
INSTALL_SUBST+=		GROUP="daemon"
INSTALL_SUBST+=		ADDUSER="${ADDUSER:Q}"
INSTALL_SUBST+=		ADDGROUP="${ADDGROUP:Q}"
INSTALL_SUBST+=		ID="${ID:Q}"
INSTALL_SUBST+=		CAT="${CAT:Q}"
INSTALL_SUBST+=		MKDIR="${MKDIR:Q}"
INSTALL_SUBST+=		RMDIR="${RMDIR:Q}"
INSTALL_SUBST_SED=	${INSTALL_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

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

pre-install:
	${SED} ${INSTALL_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${INSTALL_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	(cd ${WRKSRC}/gnats;   ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-info)
	(cd ${WRKSRC}/send-pr; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} install-info)
	${INSTALL_INFO} ${PREFIX}/info/gnats.info   ${PREFIX}/info/dir
	${INSTALL_INFO} ${PREFIX}/info/send-pr.info ${PREFIX}/info/dir

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
