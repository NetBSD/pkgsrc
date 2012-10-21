# $NetBSD: Makefile,v 1.32 2012/10/21 16:01:40 cheusov Exp $
#

DISTNAME=	sendfile-2.1b
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://fex.rus.uni-stuttgart.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fex.rus.uni-stuttgart.de/saft/sendfile.html
COMMENT=	Implementation of the Simple asynchronous file transfer protocol
LICENSE=	gnu-gpl-v2

#WRKSRC=		${WRKDIR}/sendfile-2.1b

PKG_DESTDIR_SUPPORT=	user-destdir
DIST_SUBDIR=		${PKGNAME_NOREV}

EGDIR=		${PREFIX}/share/examples/sendfile
CONF_FILES=	${EGDIR}/sendfile.cf ${PKG_SYSCONFDIR}/sendfile.cf
CONF_FILES+=	${EGDIR}/sendfile.deny ${PKG_SYSCONFDIR}/sendfile.deny

OVERRIDE_GNU_CONFIG_SCRIPTS=	yes

SUBST_CLASSES+=		makeconfig
SUBST_STAGE.makeconfig=	pre-configure
SUBST_FILES.makeconfig=	makeconfig
SUBST_VARS.makeconfig=	PREFIX PKG_SYSCONFBASEDIR

post-configure:
	cd ${WRKSRC} &&${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} config

OWN_DIRS+=	${VARBASE}/spool/sendfile
OWN_DIRS_PERMS+=${VARBASE}/spool/sendfile/LOG ${ROOT_USER} ${ROOT_GROUP} 700
OWN_DIRS_PERMS+=${VARBASE}/spool/sendfile/OUTGOING ${ROOT_USER} ${ROOT_GROUP} 1777

.include "../../mk/bsd.pkg.mk"
