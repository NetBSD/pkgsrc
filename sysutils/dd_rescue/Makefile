# $NetBSD: Makefile,v 1.10 2026/08/04 20:29:15 wiz Exp $

DISTNAME=	dd_rescue-1.33
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE:Q}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.garloff.de/kurt/linux/ddrescue/
COMMENT=	Tool like dd(1) for rescuing data from media with errors
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/dd_rescue

BUILD_TARGET=	dd_rescue

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dd_rescue ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/README.dd_rescue \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
