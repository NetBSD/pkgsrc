# $NetBSD: Makefile,v 1.20 2016/04/20 12:10:27 nros Exp $
#

DISTNAME=	libmad-0.15.1b
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder
LICENSE=	gnu-gpl-v2

CONFLICTS=	mad<0.15

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	lib/pkgconfig

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'			\
		-e 's,@VERSION@,${PKGVERSION},g'		\
		< ${FILESDIR}/mad.pc.in > ${WRKDIR}/mad.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
