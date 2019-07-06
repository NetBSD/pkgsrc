# $NetBSD: Makefile,v 1.4 2019/07/06 19:12:47 nia Exp $
#

DISTNAME=	aspell6-csb-0.02-0
PKGNAME=	${DISTNAME:S/6-/-/1:S/-0$/.0/1}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/csb/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	Kashubian language support for aspell
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

.include "../../mk/bsd.prefs.mk"
.if ${PKG_FORMAT} == "pkg" && ${OPSYS} == "Linux"
BROKEN=	Non-ASCII PLIST and thus problem with libarchive on glibc systems.
.endif

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
