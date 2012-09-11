# $NetBSD: Makefile,v 1.24 2012/09/12 00:24:42 asau Exp $
#

DISTNAME=	libid3tag-0.15.1b
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/}

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	ID3 tag library, part of MAD (MPEG Audio Decoder)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS=	mad<0.15

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS=	lib/pkgconfig

post-build:
	${SED}	-e 's,@PREFIX@,${PREFIX},g'			\
		-e 's,@VERSION@,${PKGVERSION},g'		\
		< ${FILESDIR}/id3tag.pc.in > ${WRKDIR}/id3tag.pc

post-install:
	${INSTALL_DATA} ${WRKDIR:Q}/id3tag.pc ${DESTDIR:Q}${PREFIX:Q}/lib/pkgconfig

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
