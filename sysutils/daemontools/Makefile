# $NetBSD: Makefile,v 1.51 2023/09/04 17:50:48 schmonz Exp $

DISTNAME=		daemontools-0.76
PKGREVISION=		5
CATEGORIES=		sysutils
MASTER_SITES=		http://cr.yp.to/daemontools/ ftp://cr.yp.to/daemontools/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${MANPAGES}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/daemontools.html
COMMENT=		Service monitoring and logging utilities by djb
LICENSE=		public-domain

MANPAGES=		${DISTNAME}-man-20020131.tar.gz
SITES.${MANPAGES}=	http://smarden.org/pape/djb/manpages/

CONFLICTS+=		daemontools-encore-[0-9]*

WRKSRC=			${WRKDIR}/admin/${PKGNAME_NOREV}
DJB_SLASHPACKAGE=	YES
TEST_TARGET=		rts
TEST_DIRS=		compile

CMDDIR=			${WRKSRC}/command

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man8

SUBST_CLASSES+=		djberrno
SUBST_FILES.djberrno=	src/error.h

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	src/svscanboot.sh
SUBST_SED.paths=	-e 's|/usr/local/sbin:/bin|/usr/local/sbin:${PREFIX}/bin:${PREFIX}/sbin:/bin|g'
SUBST_SED.paths+=	-e 's|/command/svc |${PREFIX}/bin/svc |g'

MAKE_ENV+=		PKGSRC_SHELL=${TOOLS_PLATFORM.sh}

.include "options.mk"

do-install:
	(while read cmd; do \
	  if [ $$cmd = svscanboot ]; then \
	    ${INSTALL_SCRIPT} ${CMDDIR}/$$cmd ${DESTDIR}${PREFIX}/bin; \
	  else \
	    ${INSTALL_PROGRAM} ${CMDDIR}/$$cmd ${DESTDIR}${PREFIX}/bin; \
	  fi \
	done) < ${WRKSRC}/package/commands
	cd ${WRKDIR}/*-man; for i in 8; do		 		\
	for j in *.$$i; do ${INSTALL_MAN} $$j ${DESTDIR}${PREFIX}/${PKGMANDIR}/man$$i; done \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
