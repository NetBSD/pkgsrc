# $NetBSD: Makefile,v 1.7 2004/03/01 15:54:45 adam Exp $
#

DISTNAME=	libmad-0.15.1b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

CONFLICTS=	mad<0.15

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'			\
		-e 's,@VERSION@,${PKGVERSION},g'		\
		< ${FILESDIR}/mad.pc.in > ${WRKDIR}/mad.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/mad.pc ${PREFIX}/lib/pkgconfig

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
