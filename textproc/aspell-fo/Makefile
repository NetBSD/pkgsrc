# $NetBSD: Makefile,v 1.9 2019/07/06 19:13:33 nia Exp $

DISTNAME=	aspell-fo-0.4.2
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://fo.speling.org/filer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Faroese language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-faroese-[0-9]*
USE_TOOLS+=	perl
REPLACE_PERL=	unsq

INSTALLATION_DIRS+=	lib/aspell share/aspell

.include "../../mk/bsd.prefs.mk"
.if ${PKG_FORMAT} == "pkg" && ${OPSYS} == "Linux"
BROKEN=	Can not be packaged on Linux
.endif

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
