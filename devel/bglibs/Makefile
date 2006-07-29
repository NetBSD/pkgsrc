# $NetBSD: Makefile,v 1.16 2006/07/29 00:58:51 schmonz Exp $
#

DISTNAME=		bglibs-1.100
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

USE_TOOLS+=		perl:run
MAKE_ENV+=		PERL5=${TOOLS_PERL5:Q}
USE_LIBTOOL=		yes

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/include/bglibs > conf-include;	\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/lib/bglibs > conf-lib;

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
