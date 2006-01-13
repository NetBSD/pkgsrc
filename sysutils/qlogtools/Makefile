# $NetBSD: Makefile,v 1.6 2006/01/13 18:58:58 joerg Exp $
#

DISTNAME=		qlogtools-3.1
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://untroubled.org/qlogtools/
COMMENT=		Tools useful in analyzing logs from qmail and other pkgs

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

SUBST_FILES.djbware+=	qfilelog.c

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	./installer;							\
	./instcheck

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
