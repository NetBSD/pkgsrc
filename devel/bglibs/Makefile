# $NetBSD: Makefile,v 1.12 2005/12/02 17:18:05 schmonz Exp $
#

DISTNAME=		bglibs-1.031
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
