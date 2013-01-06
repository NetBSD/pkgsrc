# $NetBSD: Makefile,v 1.23 2013/01/06 00:33:46 wiz Exp $

DISTNAME=	gob2-2.0.19
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		lex pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
LIBS+=	-lfl
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
