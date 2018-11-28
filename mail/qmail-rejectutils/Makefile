# $NetBSD: Makefile,v 1.3 2018/11/28 16:06:34 schmonz Exp $

DISTNAME=		netqmail-1.06
PKGNAME=		qmail-rejectutils-${RJPATCHVERSION}
CATEGORIES=		mail
MASTER_SITES=		http://www.qmail.org/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://schmonz.com/qmail/rejectutils/
COMMENT=		Reject messages at SMTP according to multiple criteria
LICENSE=		public-domain

RJPATCHVERSION=		20181128
RJPATCH=		${DISTNAME}-rejectutils-${RJPATCHVERSION}.patch
PATCHFILES+=		${RJPATCH}
SITES.${RJPATCH}=	${HOMEPAGE}

CONFLICTS+=		qmail<=1.03nb32

DJB_RESTRICTED=		no
BUILD_TARGET=		rejectutils

REJECTUTILS=		qmail-qfilter-ofmipd-queue	\
			qmail-qfilter-queue		\
			qmail-qfilter-smtpd-queue	\
			qmail-qfilter-viruscan		\
			qmail-rcptcheck			\
			qmail-rcptcheck-badrcptto	\
			qmail-rcptcheck-qregex		\
			qmail-rcptcheck-realrcptto

INSTALLATION_DIRS=	bin

do-install:
	for i in ${REJECTUTILS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$i ${DESTDIR}${PREFIX}/bin/$$i; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
