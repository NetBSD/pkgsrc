# $NetBSD: Makefile,v 1.14 2005/06/18 05:57:05 hira Exp $
#

DISTNAME=	ser-0.8.10_src
PKGNAME=	ser-0.8.10
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/latest/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.iptel.org/ser/
COMMENT=	SIP express router

WRKSRC=		${WRKDIR}/ser-0.8.10

USE_TOOLS+=	gmake
USE_PKGINSTALL=	yes

PKG_SYSCONFSUBDIR=	ser
EGDIR=			${PREFIX}/share/examples/ser
CONF_FILES=		${EGDIR}/ser.cfg ${PKG_SYSCONFDIR}/ser.cfg

MAKE_DIRS=	${EGDIR}

MAKE_ENV+= BUILDLINK_PREFIX.pthread=${BUILDLINK_PREFIX.pthread:Q}
MAKE_ENV+= BUILDLINK_PREFIX.mysql-client=${BUILDLINK_PREFIX.mysql-client:Q}
MAKE_ENV+= BUILDLINK_PREFIX.expat=${BUILDLINK_PREFIX.expat:Q}
MAKE_ENV+= EGDIR=${EGDIR}

.include "../../mk/mysql.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
