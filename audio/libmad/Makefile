# $NetBSD: Makefile,v 1.15 2006/11/05 17:14:20 joerg Exp $
#

DISTNAME=	libmad-0.15.1b
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

CONFLICTS=	mad<0.15

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

INSTALLATION_DIRS=	lib/pkgconfig

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'			\
		-e 's,@VERSION@,${PKGVERSION},g'		\
		< ${FILESDIR}/mad.pc.in > ${WRKDIR}/mad.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
