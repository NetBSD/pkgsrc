# $NetBSD: Makefile,v 1.8 2002/02/18 15:14:17 seb Exp $

DISTNAME=	nano-1.0.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
