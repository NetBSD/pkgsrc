# $NetBSD: Makefile,v 1.2 2002/09/01 05:00:27 schmonz Exp $
#

DISTNAME=	p4d
HOMEPAGE=	http://www.perforce.com/perforce/products/p4d.html
COMMENT=	Perforce SCM server

P4BINONLY=	# defined

.include "../../devel/p4/Makefile.common"

FILES_SUBST+=	P4USER=${P4USER:Q}
FILES_SUBST+=	P4ROOT=${P4ROOT:Q}
FILES_SUBST+=	P4PORT=${P4PORT:Q}
FILES_SUBST+=	P4LOG=${P4LOG:Q}
FILES_SUBST+=	P4JOURNAL=${P4JOURNAL:Q}

PKG_GROUPS?=	${P4GROUP}
PKG_USERS?=	${P4USER}:${P4GROUP}::Perforce\\ Server:${P4ROOT}

OWN_DIRS_PERMS=	${P4ROOT} ${P4USER} ${P4GROUP} 750

RCD_SCRIPTS=	p4d

.include "../../mk/bsd.prefs.mk"

P4LOG?=		log
P4JOURNAL?=	journal

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} ${PREFIX}/sbin
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/p4d.sh > ${WRKDIR}/p4d
	${INSTALL_SCRIPT} ${WRKDIR}/p4d ${RCD_SCRIPTS_EXAMPLEDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
