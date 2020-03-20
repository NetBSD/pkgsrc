# $NetBSD: Makefile,v 1.17 2020/03/20 11:57:46 nia Exp $
#

DISTNAME=	xye-0.12.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xye/0.12.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xye.sourceforge.net/
COMMENT=	Kye clone

GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc
USE_LANGUAGES=		c c++03

SUBST_CLASSES+=		crlf
SUBST_MESSAGE.crlf=	stripping EOL CR
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	*/*
SUBST_FILTER_CMD.crlf=	${TR} -d '\r'

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
