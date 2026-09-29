# $NetBSD: Makefile,v 1.33 2026/09/29 06:04:23 wiz Exp $

DISTNAME=	gob2-2.0.20
PKGREVISION=	7
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
