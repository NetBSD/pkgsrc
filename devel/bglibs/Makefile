# $NetBSD: Makefile,v 1.24 2012/10/31 11:16:40 asau Exp $
#

DISTNAME=		bglibs-1.106
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter

USE_TOOLS+=		perl:run
MAKE_ENV+=		PERL5=${TOOLS_PERL5:Q}
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}
USE_LIBTOOL=		yes

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO
TEST_TARGET=		selftests

DJB_CONFIG_CMDS=							\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/include/bglibs > conf-include;	\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/lib/bglibs > conf-lib;

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
