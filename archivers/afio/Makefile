# $NetBSD: Makefile,v 1.5 2004/05/02 22:23:58 danw Exp $

DISTNAME=	afio-2.5
CATEGORIES=	archivers
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/system/backup/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/afio/
COMMENT=	cpio-format archive creator with data corruption handling

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes
ALL_TARGET=	afio

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
# Don't define HAVE_LCHOWN
MAKE_FLAGS+=	e2=
.endif

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/bsd.pkg.mk"
