# $NetBSD: Makefile,v 1.47 2009/07/18 19:32:38 wiz Exp $
#

DISTNAME=	indent-2.2.9
PKGNAME=	g${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=	GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=	GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
