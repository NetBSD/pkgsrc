# $NetBSD: Makefile,v 1.11 2002/12/26 15:14:41 shell Exp $

DISTNAME=	nano-1.0.9
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	shell@netbsd.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
