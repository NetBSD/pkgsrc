# $NetBSD: Makefile,v 1.11 2020/01/26 17:32:11 rillig Exp $
#

DISTNAME=		qlogtools-3.1
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://untroubled.org/qlogtools/
COMMENT=		Tools useful in analyzing logs from qmail and other pkgs

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

SUBST_FILES.djbware+=	qfilelog.c

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-configure:
	${ECHO} ${DESTDIR}${DJB_CONFIG_PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${DESTDIR}${DJB_CONFIG_PREFIX}/${PKGMANDIR} > ${WRKSRC}/conf-man

do-install:
	${RUN} cd ${WRKSRC} && ./installer && ./instcheck

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
