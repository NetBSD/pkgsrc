# $NetBSD: Makefile,v 1.23 2010/02/11 21:57:09 joerg Exp $

DISTNAME=		LambdaMOO-1.8.1
PKGNAME=		lambdamoo-1.8.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lambdamoo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/lambdamoo/
COMMENT=		The definitive MOO software

PKG_DESTDIR_SUPPORT=	user-destdir

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

OWN_DIRS_PERMS+=	${LAMBDAMOO_HOME} ${LAMBDAMOO_USER} ${LAMBDAMOO_GROUP} 700

FILES_SUBST+=		LAMBDAMOO_HOME=${LAMBDAMOO_HOME:Q}

WRKSRC=			${WRKDIR}/MOO-1.8.1
BUILD_TARGET=
GNU_CONFIGURE=		yes
USE_TOOLS+=		yacc
INSTALLATION_DIRS=	sbin share/lambdamoo share/doc/lambdamoo

pre-build:
	${MV} ${WRKSRC}/restart.sh ${WRKSRC}/restart.sh.in
	${SED} <${WRKSRC}/restart.sh.in >${WRKSRC}/restart.sh	\
		"s|__PREFIX__|${PREFIX}|g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/moo ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/restart.sh ${DESTDIR}${PREFIX}/share/lambdamoo
	${INSTALL_DATA} ${WRKSRC}/Minimal.db ${DESTDIR}${PREFIX}/share/lambdamoo
	${INSTALL_DATA} \
		${WRKSRC}/README \
		${WRKSRC}/README.Minimal \
		${DESTDIR}${PREFIX}/share/doc/lambdamoo/

.include "../../mk/bsd.pkg.mk"
