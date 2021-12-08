# $NetBSD: Makefile,v 1.29 2021/12/08 16:03:57 adam Exp $

DISTNAME=	gob2-2.0.20
PKGREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	lex:run pkg-config
GNU_CONFIGURE=	yes

LIBS.NetBSD+=	-lfl

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
