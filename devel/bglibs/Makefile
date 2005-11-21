# $NetBSD: Makefile,v 1.10 2005/11/21 05:37:36 schmonz Exp $
#

DISTNAME=		bglibs-1.027
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX}/include/bglibs > conf-include;	\
	${ECHO} ${DJB_CONFIG_PREFIX}/lib/bglibs > conf-lib;

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
