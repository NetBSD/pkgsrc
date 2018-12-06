# $NetBSD: Makefile,v 1.1 2018/12/06 00:07:33 schmonz Exp $

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

LDFLAGS.SunOS+=		-lnsl

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} ${LDFLAGS} -lspf2 -o ${PKGBASE} ${DISTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
