# $NetBSD: Makefile,v 1.4 2000/12/05 15:47:23 veego Exp $
#

DISTNAME=		libpcap-0.4
CATEGORIES=		net
MASTER_SITES= 		ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

INSTALL_TARGET=		install install-incl install-man

pre-install:
	-${MKDIR} ${LOCALBASE}/include/net

.include "../../mk/bsd.pkg.mk"
