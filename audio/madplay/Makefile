# $NetBSD: Makefile,v 1.10 2001/02/13 06:10:11 simonb Exp $
#

DISTNAME=	mad-0.12.5b
PKGNAME=	${DISTNAME:S/mad/madplay/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mad/} \
		ftp://ftp.mars.org/pub/mpeg/

MAINTAINER=	simonb@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/mad/

BUILD_DEPENDS+= msgfmt:../../devel/gettext

GNU_CONFIGURE=	YES
USE_LIBINTL=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
