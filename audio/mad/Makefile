# $NetBSD: Makefile,v 1.6 2002/08/26 06:45:38 jlam Exp $
#

DISTNAME=	mad-0.14.2b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

BUILD_USES_MSGFMT=	YES

CONFLICTS=	madplay-[0-9]*

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/esound/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
