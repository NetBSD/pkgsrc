# $NetBSD: Makefile,v 1.9 2001/02/09 13:12:23 simonb Exp $
#

DISTNAME=	mad-0.12.4b
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
