# $NetBSD: Makefile,v 1.4 2003/07/10 08:40:14 wiz Exp $
#

DISTNAME=	libid3tag-0.15.0b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	ID3 tag library, part of MAD (MPEG Audio Decoder)

CONFLICTS=	mad<0.15

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
