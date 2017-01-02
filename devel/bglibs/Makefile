# $NetBSD: Makefile,v 1.32 2017/01/02 14:13:32 schmonz Exp $
#

DISTNAME=		bglibs-2.03
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/bglibs/
COMMENT=		Collection of libraries by Bruce Guenter
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		perl:run gmake
MAKE_ENV+=		PERL5=${TOOLS_PERL5:Q}
INSTALL_ENV+=		install_prefix=${DESTDIR:Q}
USE_LIBTOOL=		yes

DJB_RESTRICTED=		NO
DJB_MAKE_TARGETS=	NO
TEST_TARGET=		selftests

DJB_CONFIG_CMDS=						\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/include > conf-include;	\
	${ECHO} ${DJB_CONFIG_PREFIX:Q}/lib > conf-lib;

CFLAGS.SunOS+=		-DSOL_TCP=SOL_SOCKET

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
