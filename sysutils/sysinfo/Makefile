# $NetBSD: Makefile,v 1.2 2001/02/17 17:42:19 wiz Exp $
#

DISTNAME=		sysinfo-3.5.1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.rge.com/pub/admin/sysinfo/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.magnicomp.com/
COMMENT=		displays system hardware and software information and configuration

LICENSE=		shareware

ONLY_FOR_PLATFORM=	SunOS-*-*      # only for Solaris, at the moment

ALL_TARGET=		default
INSTALL_TARGET=		install install.man
MAKE_ENV+=		CPPFLAGS= CC=${CC}

post-build:
	${CHMOD} -R o+rx ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
