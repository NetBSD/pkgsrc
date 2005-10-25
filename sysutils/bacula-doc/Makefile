# $NetBSD: Makefile,v 1.1.1.1 2005/10/25 04:20:33 minskim Exp $
#

DISTNAME=		bacula-doc-1.36.3
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Documentation for Bacula - The Network Backup Solution

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/bacula
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

post-extract:
	${RM} -rf ${WRKSRC}/CVS ${WRKSRC}/publishdoc ${WRKSRC}/*.bak

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe [A-Za-z]* ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
