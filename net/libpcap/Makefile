# $NetBSD: Makefile,v 1.3 1999/07/02 08:46:52 agc Exp $
#

DISTNAME=		libpcap-0.4
CATEGORIES=		net
MASTER_SITES= 		ftp://ftp.ee.lbl.gov/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

INSTALL_TARGET+=	install-incl install-man

pre-install:
	-${MKDIR} ${LOCALBASE}/include/net

.include "../../mk/bsd.pkg.mk"
