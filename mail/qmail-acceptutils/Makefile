# $NetBSD: Makefile,v 1.19 2026/08/03 13:12:29 wiz Exp $

DISTNAME=		netqmail-1.06
PKGNAME=		qmail-acceptutils-${ACPATCHVERSION}
CATEGORIES=		mail
MASTER_SITES=		http://netqmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://schmonz.com/software/acceptutils/
COMMENT=		TLS and AUTH for qmail without patching
LICENSE=		public-domain

ACPATCHVERSION=		20230511
ACPATCH=		${DISTNAME}-acceptutils-${ACPATCHVERSION}.patch
PATCHFILES+=		${ACPATCH}
PATCH_DIST_STRIP=	-p0
SITES.${ACPATCH}=	${HOMEPAGE}

DEPENDS+=		mess822-[0-9]*:../../mail/mess822
DEPENDS+=		ucspi-ssl-[0-9]*:../../net/ucspi-ssl

CONFLICTS+=		qmail<=1.03nb32

BUILD_TARGET=		acceptutils

USE_LANGUAGES=		c c99

ACCEPTUTILS=		authup checknotroot fixsmtpio \
			qmail-qfilter-addtlsheader

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	for i in ${ACCEPTUTILS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin/$$i; \
		${INSTALL_MAN} ${WRKSRC}/$$i.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$$i.8; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
