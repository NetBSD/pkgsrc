# $NetBSD: Makefile,v 1.1 2020/11/02 10:24:58 schmonz Exp $

DISTNAME=		qremote-20131231
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mojzis.com/software/qremote/
COMMENT=		Experimental qmail-remote replacement with CurveCP support
LICENSE=		public-domain

DEPENDS+=		{ucspi-tcp6-[0-9]*,ucspi-tcp-[0-9]*}:../../net/ucspi-tcp

DJB_RESTRICTED=		no

USE_LANGUAGES=		c c++

MAKE_JOBS_SAFE=		no

BUILD_DEFS+=		QMAILDIR

INSTALLATION_DIRS=	bin

post-build:
	cd ${WRKSRC} && ${MV} qmail-remote qmail-qremote

do-install:
	for i in qremote curvecpclient curvecpmessage rsmtp; do \
	  ${INSTALL_PROGRAM} ${WRKSRC}/qmail-$${i} ${DESTDIR}${PREFIX}/bin; \
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
