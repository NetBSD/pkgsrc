# $NetBSD: Makefile,v 1.14 2022/06/28 11:36:08 wiz Exp $

DISTNAME=	aspell-fo-0.4.2
PKGREVISION=	9
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
BROKEN=	"Non-ASCII PLIST and thus problem with libarchive on glibc systems."
.endif

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
