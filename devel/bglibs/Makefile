# $NetBSD: Makefile,v 1.13 2006/02/20 02:59:51 schmonz Exp $
#

DISTNAME=		bglibs-1.040
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/include/bglibs > conf-include;	\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/lib/bglibs > conf-lib;

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
