# $NetBSD: Makefile,v 1.62 2018/11/14 22:21:32 kleink Exp $

DISTNAME=		teg-0.11.1
PKGREVISION=		54
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=teg/}

MAINTAINER=		wrzymski@gmail.com
HOMEPAGE=		http://teg.sourceforge.net/
COMMENT=		Round-based computer board game

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config

GCONF_SCHEMAS+=	teg.schemas

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
