# $NetBSD: Makefile,v 1.36 2016/05/17 10:32:08 fhajny Exp $
#

DISTNAME=	sendfile-2.1b
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://fex.rus.uni-stuttgart.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fex.rus.uni-stuttgart.de/saft/sendfile.html
COMMENT=	Implementation of the Simple asynchronous file transfer protocol
LICENSE=	gnu-gpl-v2

CONFLICTS=	jabberd2-[0-9]*

#WRKSRC=		${WRKDIR}/sendfile-2.1b

DIST_SUBDIR=		${PKGNAME_NOREV}

EGDIR=		${PREFIX}/share/examples/sendfile
CONF_FILES=	${EGDIR}/sendfile.cf ${PKG_SYSCONFDIR}/sendfile.cf
CONF_FILES+=	${EGDIR}/sendfile.deny ${PKG_SYSCONFDIR}/sendfile.deny

OVERRIDE_GNU_CONFIG_SCRIPTS=	yes

post-configure:
	cd ${WRKSRC} &&${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} config

OWN_DIRS+=	${VARBASE}/spool/sendfile
OWN_DIRS_PERMS+=${VARBASE}/spool/sendfile/LOG ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
OWN_DIRS_PERMS+=${VARBASE}/spool/sendfile/OUTGOING ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777

.include "../../mk/bsd.pkg.mk"
