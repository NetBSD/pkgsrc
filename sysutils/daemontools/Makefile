# $NetBSD: Makefile,v 1.30 2008/02/19 13:59:04 schmonz Exp $

DISTNAME=		daemontools-0.76
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/daemontools/ ftp://cr.yp.to/daemontools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/daemontools.html
COMMENT=		Service monitoring and logging utilities by djb

MANPAGES=		${DISTNAME}-man-20020131.tar.gz
SITES.${MANPAGES}=	http://smarden.org/pape/djb/manpages/

DJB_RESTRICTED=		no

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/admin/${DISTNAME}
DJB_SLASHPACKAGE=	YES

CMDDIR=			${WRKSRC}/command

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man8

SUBST_FILES.djbware+=	src/error.h

do-install:
	(while read cmd; do \
	  if ${FILE_CMD} ${CMDDIR}/$$cmd | ${EGREP} "(executable .* script|shell script|text)" >/dev/null 2>&1; then \
	    ${INSTALL_SCRIPT} ${CMDDIR}/$$cmd ${PREFIX}/bin; \
	  else \
	    ${INSTALL_PROGRAM} ${CMDDIR}/$$cmd ${PREFIX}/bin; \
	  fi \
	done) < ${WRKSRC}/package/commands

post-install:
	cd ${WRKDIR}/*-man; for i in 8; do		 		\
	for j in *.$$i; do ${INSTALL_MAN} $$j ${PREFIX}/${PKGMANDIR}/man$$i; done \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
