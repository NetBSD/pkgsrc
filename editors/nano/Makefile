# $NetBSD: Makefile,v 1.17 2003/09/27 17:07:35 grant Exp $

DISTNAME=	nano-1.0.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU:=nano/}

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://www.nano-editor.org/
COMMENT=	Small and friendly text editor (a free replacement for Pico)

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=	nano.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
