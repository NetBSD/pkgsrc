# $NetBSD: Makefile,v 1.5 2001/11/22 09:23:15 martti Exp $

DISTNAME=	nano-1.0.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
