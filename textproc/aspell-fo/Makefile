# $NetBSD: Makefile,v 1.1 2013/04/09 02:33:42 rodent Exp $

DISTNAME=	aspell-fo-0.2.38
CATEGORIES=	textproc
MASTER_SITES=	http://fo.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fo.speling.org/
COMMENT=	Faroese language support for aspell

USE_TOOLS+=	perl
REPLACE_PERL=	unsq

INSTALLATION_DIRS+=	lib/aspell share/aspell

.include "../../mk/bsd.prefs.mk"
.if ${PKG_FORMAT} == "pkg" && ${OPSYS} == "Linux"
BROKEN=	Can not be packaged on Linux
.endif

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
