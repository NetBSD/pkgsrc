# $NetBSD: Makefile,v 1.6 2003/12/17 03:23:46 simonb Exp $
#

DISTNAME=	libid3tag-0.15.0b
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	ID3 tag library, part of MAD (MPEG Audio Decoder)

CONFLICTS=	mad<0.15

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'			\
		-e 's,@VERSION@,${PKGVERSION},g'		\
		< ${FILESDIR}/id3tag.pc.in > ${WRKDIR}/id3tag.pc

post-install:
	${INSTALL_DATA} ${WRKDIR}/id3tag.pc ${PREFIX}/lib/pkgconfig


.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
