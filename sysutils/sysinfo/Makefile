# $NetBSD: Makefile,v 1.6 2003/07/21 17:24:39 martti Exp $
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
MAKE_ENV+=		CPPFLAGS="" CC="${CC}"

post-build:
	${CHMOD} -R o+rx ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
