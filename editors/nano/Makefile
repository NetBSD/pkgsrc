# $NetBSD: Makefile,v 1.19 2004/02/12 14:34:06 minskim Exp $

DISTNAME=	nano-1.0.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	Small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=	nano.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
