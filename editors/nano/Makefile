# $NetBSD: Makefile,v 1.14 2003/07/17 21:34:43 grant Exp $

DISTNAME=	nano-1.0.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

USE_NEW_TEXINFO=	YES
INFO_FILES=	nano.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
