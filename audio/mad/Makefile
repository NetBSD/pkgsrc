# $NetBSD: Makefile,v 1.2 2001/09/27 23:17:45 jlam Exp $
#

DISTNAME=	mad-0.13.0b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

PATCH_SITES=	ftp://ftp.mars.org/pub/mpeg/testing/
PATCHFILES=	tty-0.13.0b.patch

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/
COMMENT=	High-quality MPEG audio decoder

BUILD_USES_MSGFMT=	yes

CONFLICTS=	madplay-[0-9]*

GNU_CONFIGURE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
