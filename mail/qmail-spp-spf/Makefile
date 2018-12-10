# $NetBSD: Makefile,v 1.2 2018/12/10 22:38:24 schmonz Exp $

DISTNAME=		qmail-spp-spf-20091020.c
PKGNAME=		${DISTNAME:S/.c$//}
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		# none

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.caputo.com/foss/qmail-spp-spf/
COMMENT=		Plugin for qmail-spp that performs SPF lookups
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-build:
	cd ${WRKSRC} && \
	${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c ${DISTNAME} && \
	${LIBTOOL} --mode=link ${CC} ${LDFLAGS} -lspf2 -o ${PKGBASE} ${DISTNAME}

do-install:
	cd ${WRKSRC} && \
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE} && \
	${INSTALL_DATA} ${DISTNAME} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
