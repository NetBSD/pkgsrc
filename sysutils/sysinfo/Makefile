# $NetBSD: Makefile,v 1.7 2003/07/24 12:10:29 seb Exp $
#

DISTNAME=		sysinfo-3.5.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.rge.com/pub/admin/sysinfo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.magnicomp.com/
COMMENT=		Displays system hardware and software information and configuration

LICENSE=		shareware

ONLY_FOR_PLATFORM=	SunOS-*-*      # only for Solaris, at the moment

ALL_TARGET=		default
INSTALL_TARGET=		install install.man
TEST_TARGET=		test
MAKE_ENV+=		CPPFLAGS="" CC="${CC}"

post-build:
	${CHMOD} -R o+rx ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
