# $NetBSD: Makefile,v 1.13 2012/10/31 11:17:35 asau Exp $
#

DISTNAME=	p4d
HOMEPAGE=	http://www.perforce.com/perforce/products/p4d.html
PKGREVISION=	1
COMMENT=	Perforce SCM server

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

BUILD_DEFS+=	P4ROOT P4PORT

FILES_SUBST+=	P4USER=${P4USER:Q}
FILES_SUBST+=	P4ROOT=${P4ROOT:Q}
FILES_SUBST+=	P4PORT=${P4PORT:Q}
FILES_SUBST+=	P4LOG=${P4LOG:Q}
FILES_SUBST+=	P4JOURNAL=${P4JOURNAL:Q}

PKG_GROUPS?=	${P4GROUP}
PKG_USERS?=	${P4USER}:${P4GROUP}

PKG_GROUPS_VARS+=	P4GROUP
PKG_USERS_VARS+=	P4USER

PKG_GECOS.${P4USER}?=	Perforce Server
PKG_HOME.${P4USER}?=	${P4ROOT}

OWN_DIRS_PERMS=	${P4ROOT} ${P4USER} ${P4GROUP} 750

RCD_SCRIPTS=	p4d

.include "../../mk/bsd.prefs.mk"

P4LOG?=		log
P4JOURNAL?=	journal

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
