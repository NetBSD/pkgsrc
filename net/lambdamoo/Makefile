# $NetBSD: Makefile,v 1.14 2005/06/17 03:50:25 jlam Exp $

DISTNAME=		LambdaMOO-1.8.1
PKGNAME=		lambdamoo-1.8.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.place.org/pub/moo/ \
			${MASTER_SITE_SOURCEFORGE:=lambdamoo/} \
			ftp://ftp.kanga.nu/pub/mirrors/download.sourceforge.net/lambdamoo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lambdamoo/
COMMENT=		The definitive MOO software

DEPENDS+=		lambdamoo-core>=990412:../../net/lambdamoo-core
DEPENDS+=		lambdamoo-doc>=1.8.0p6:../../net/lambdamoo-doc

LAMBDAMOO_USER?=	lambdamoo
LAMBDAMOO_GROUP?=	lambdamoo
LAMBDAMOO_HOME?=	${PREFIX}/share/${LAMBDAMOO_USER}

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

PKG_GROUPS=		${LAMBDAMOO_GROUP}
PKG_USERS=		${LAMBDAMOO_USER}:${LAMBDAMOO_GROUP}
_PKG_USER_HOME=		${LAMBDAMOO_HOME}
_PKG_USER_SHELL=	${SH}

FILES_SUBST+=		LAMBDAMOO_HOME=${LAMBDAMOO_HOME}

WRKSRC=			${WRKDIR}/MOO-1.8.1
BUILD_TARGET=
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	sbin

pre-build:
	${MV} ${WRKSRC}/restart.sh ${WRKSRC}/restart.sh.in
	${SED} <${WRKSRC}/restart.sh.in >${WRKSRC}/restart.sh	\
		"s|__PREFIX__|${PREFIX}|g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/lambdamoo
	${INSTALL_SCRIPT} ${WRKSRC}/restart.sh ${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/Minimal.db ${PREFIX}/share/lambdamoo
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/lambdamoo
	${INSTALL_DATA} \
		${WRKSRC}/README \
		${WRKSRC}/README.Minimal \
		${PREFIX}/share/doc/lambdamoo/

post-install:
	${CHOWN} -R ${LAMBDAMOO_USER}:${LAMBDAMOO_GROUP} ${LAMBDAMOO_HOME}
	${CHMOD} u+w ${LAMBDAMOO_HOME}

.include "../../mk/bsd.pkg.mk"
