# $NetBSD: Makefile,v 1.17 2004/10/03 00:14:50 tv Exp $
#

DISTNAME=	feh-1.2.6
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.linuxbrit.co.uk/feh/
COMMENT=	Advanced image viewer

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=	YES

CONFIGURE_ARGS+=--program-transform-name=s,cam,feh_cam,
REPLACE_PERL=	${WRKSRC}/cam/cam

.include "../../devel/giblib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
