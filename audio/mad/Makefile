# $NetBSD: Makefile,v 1.4 2001/10/27 21:29:49 jlam Exp $
#

DISTNAME=	mad-0.14.0b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

BUILD_USES_MSGFMT=	YES

CONFLICTS=	madplay-[0-9]*

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
