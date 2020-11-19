# $NetBSD: Makefile,v 1.9 2020/11/19 09:35:41 schmonz Exp $

DISTNAME=		netqmail-1.06
PKGNAME=		qmail-rejectutils-${RJPATCHVERSION}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://netqmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://schmonz.com/qmail/rejectutils/
COMMENT=		Reject messages at SMTP according to multiple criteria
LICENSE=		public-domain

RJPATCHVERSION=		20181230
RJPATCH=		${DISTNAME}-rejectutils-${RJPATCHVERSION}.patch
PATCHFILES+=		${RJPATCH}
SITES.${RJPATCH}=	${HOMEPAGE}

CONFLICTS+=		qmail<=1.03nb32

BUILD_TARGET=		rejectutils

REJECTUTILS=		qmail-qfilter-queue		\
			qmail-qfilter-viruscan		\
			qmail-rcptcheck			\
			qmail-rcptcheck-badrcptto	\
			qmail-rcptcheck-qregex		\
			qmail-rcptcheck-realrcptto

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	for i in ${REJECTUTILS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin/$$i; \
		${INSTALL_MAN} ${WRKSRC}/$$i.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/$$i.8; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
