# $NetBSD: Makefile,v 1.22 2007/12/02 12:14:53 wiz Exp $

DISTNAME=		LambdaMOO-1.8.1
PKGNAME=		lambdamoo-1.8.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lambdamoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lambdamoo/
COMMENT=		The definitive MOO software

DEPENDS+=		lambdamoo-core>=990412:../../net/lambdamoo-core
DEPENDS+=		lambdamoo-doc>=1.8.0p6:../../net/lambdamoo-doc

LAMBDAMOO_USER?=	lambdamoo
LAMBDAMOO_GROUP?=	lambdamoo
LAMBDAMOO_HOME?=	${PREFIX}/share/${LAMBDAMOO_USER}

PKG_GROUPS=		${LAMBDAMOO_GROUP}
PKG_USERS=		${LAMBDAMOO_USER}:${LAMBDAMOO_GROUP}

PKG_HOME.${LAMBDAMOO_USER}=	${LAMBDAMOO_HOME}
PKG_SHELL.${LAMBDAMOO_USER}=	${SH}

PKG_GROUPS_VARS+=	LAMBDAMOO_GROUP
PKG_USERS_VARS+=	LAMBDAMOO_USER

FILES_SUBST+=		LAMBDAMOO_HOME=${LAMBDAMOO_HOME:Q}

WRKSRC=			${WRKDIR}/MOO-1.8.1
BUILD_TARGET=
GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc
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
