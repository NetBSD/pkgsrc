# $NetBSD: Makefile,v 1.5 2022/01/05 14:03:27 schmonz Exp $

DISTNAME=		qremote-20131231
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mojzis.com/software/qremote/
COMMENT=		Experimental qmail-remote replacement with CurveCP support
LICENSE=		public-domain

DEPENDS+=		nacl>=20110221nb3:../../security/nacl
DEPENDS+=		{ucspi-tcp6-[0-9]*,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp

USE_LANGUAGES=		c c++

MAKE_JOBS_SAFE=		no

BUILD_DEFS+=		QMAILDIR

INSTALLATION_DIRS=	bin

post-build:
	cd ${WRKSRC} && ${MV} qmail-remote qmail-qremote

do-install:
	for i in qremote rsmtp; do \
	  ${INSTALL_PROGRAM} ${WRKSRC}/qmail-$${i} ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/showdnsmx ${DESTDIR}${PREFIX}/bin

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
