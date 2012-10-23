# $NetBSD: Makefile,v 1.9 2012/10/23 19:51:21 asau Exp $
#

DISTNAME=		qlogtools-3.1
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://untroubled.org/qlogtools/
COMMENT=		Tools useful in analyzing logs from qmail and other pkgs

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

SUBST_FILES.djbware+=	qfilelog.c

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-configure:
	${ECHO} ${DESTDIR}${DJB_CONFIG_PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${DESTDIR}${DJB_CONFIG_PREFIX}/${PKGMANDIR} > ${WRKSRC}/conf-man

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	./installer;							\
	./instcheck

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
