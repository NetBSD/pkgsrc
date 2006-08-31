# $NetBSD: Makefile,v 1.10 2006/08/31 08:37:53 rillig Exp $
#

DISTNAME=	p4d
HOMEPAGE=	http://www.perforce.com/perforce/products/p4d.html
PKGREVISION=	1
COMMENT=	Perforce SCM server

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

BUILD_DEFS+=	P4USER P4GROUP P4ROOT P4PORT

FILES_SUBST+=	P4USER=${P4USER:Q}
FILES_SUBST+=	P4ROOT=${P4ROOT:Q}
FILES_SUBST+=	P4PORT=${P4PORT:Q}
FILES_SUBST+=	P4LOG=${P4LOG:Q}
FILES_SUBST+=	P4JOURNAL=${P4JOURNAL:Q}

PKG_GROUPS?=	${P4GROUP}
PKG_USERS?=	${P4USER}:${P4GROUP}

PKG_GECOS.${P4USER}?=	Perforce Server
PKG_HOME.${P4USER}?=	${P4ROOT}

OWN_DIRS_PERMS=	${P4ROOT} ${P4USER} ${P4GROUP} 750

RCD_SCRIPTS=	p4d

.include "../../mk/bsd.prefs.mk"

P4LOG?=		log
P4JOURNAL?=	journal

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
