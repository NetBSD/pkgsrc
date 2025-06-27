# $NetBSD: Makefile,v 1.17 2025/06/27 17:39:55 schmonz Exp $

DISTNAME=		qlogtools-3.1
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://untroubled.org/qlogtools/
COMMENT=		Tools useful in analyzing logs from qmail and other pkgs
LICENSE=		gnu-gpl-v2

FORCE_C_STD=		c89

DJB_MAKE_TARGETS=	NO
DJB_ERRNO_FIXUP=	qfilelog.c

# optind
CFLAGS.SunOS+=		-D__EXTENSIONS__

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-configure:
	${ECHO} ${DESTDIR}${DJB_CONFIG_PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${DESTDIR}${DJB_CONFIG_PREFIX}/${PKGMANDIR} > ${WRKSRC}/conf-man

do-install:
	${RUN} cd ${WRKSRC} && ./installer && ./instcheck

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
