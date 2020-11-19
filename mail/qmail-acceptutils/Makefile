# $NetBSD: Makefile,v 1.14 2020/11/19 09:35:42 schmonz Exp $

DISTNAME=		netqmail-1.06
PKGNAME=		qmail-acceptutils-${ACPATCHVERSION}
CATEGORIES=		mail
MASTER_SITES=		http://netqmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://schmonz.com/qmail/acceptutils/
COMMENT=		Offer TLS and SMTP AUTH with new features and no patch conflicts
LICENSE=		public-domain

ACPATCHVERSION=		20181228
ACPATCH=		${DISTNAME}-acceptutils-${ACPATCHVERSION}.patch
PATCHFILES+=		${ACPATCH}
SITES.${ACPATCH}=	${HOMEPAGE}

DEPENDS+=		mess822-[0-9]*:../../mail/mess822
DEPENDS+=		ucspi-ssl-[0-9]*:../../net/ucspi-ssl

CONFLICTS+=		qmail<=1.03nb32

BUILD_TARGET=		acceptutils

USE_LANGUAGES=		c c99

ACCEPTUTILS=		authup checknotroot fixsmtpio reup \
			qmail-qfilter-addtlsheader

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	for i in ${ACCEPTUTILS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin/$$i; \
		${INSTALL_MAN} ${WRKSRC}/$$i.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$$i.8; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
