# $NetBSD: Makefile,v 1.14 2005/01/16 17:15:35 minskim Exp $
#

DISTNAME=	libid3tag-0.15.1b
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	ID3 tag library, part of MAD (MPEG Audio Decoder)

CONFLICTS=	mad<0.15

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'			\
		-e 's,@VERSION@,${PKGVERSION},g'		\
		< ${FILESDIR}/id3tag.pc.in > ${WRKDIR}/id3tag.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/id3tag.pc ${PREFIX}/lib/pkgconfig

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
