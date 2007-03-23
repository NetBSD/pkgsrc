# $NetBSD: Makefile,v 1.1.1.1 2007/03/23 06:24:49 wiz Exp $
#

DISTNAME=	ser-0.8.14_src
PKGNAME=	ser-0.8.14
PKGREVISION=	1
CATEGORIES=	net comms
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/0.8.14/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.iptel.org/ser/
COMMENT=	SIP express router

WRKSRC=		${WRKDIR}/ser-0.8.14

USE_TOOLS+=	flex gmake yacc

PKG_SYSCONFSUBDIR=	ser
EGDIR=			${PREFIX}/share/examples/ser
CONF_FILES=		${EGDIR}/ser.cfg ${PKG_SYSCONFDIR}/ser.cfg

REQD_DIRS=	${EGDIR}

MAKE_ENV+= BUILDLINK_PREFIX.pthread=${BUILDLINK_PREFIX.pthread:Q}
MAKE_ENV+= cfg-prefix=${PREFIX}/share/examples
MAKE_ENV+= EGDIR=${EGDIR:Q}

CHECK_PORTABILITY_SKIP+=	scripts/sc

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
