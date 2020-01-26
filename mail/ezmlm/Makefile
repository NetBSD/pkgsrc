# $NetBSD: Makefile,v 1.27 2020/01/26 17:31:34 rillig Exp $
#

DISTNAME=		ezmlm-0.53
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cr.yp.to/ezmlm.html
COMMENT=		Easy-to-use, high-speed mailing list manager for qmail
LICENSE=		public-domain

CONFLICTS=		ezmlm-idx-[0-9]*

DEPENDS+=		qmail>=1.03:../../mail/qmail

DJB_RESTRICTED=		no
DJB_CONFIG_CMDS=	${ECHO} ${DESTDIR:Q} > conf-destdir
DJB_BUILD_TARGETS=	install
INSTALL_TARGET=		setup

INSTALLATION_DIRS=	bin man ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/cat1 ${PKGMANDIR}/cat5

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
