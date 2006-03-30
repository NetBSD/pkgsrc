# $NetBSD: Makefile,v 1.44 2006/03/30 03:44:43 jlam Exp $
#

DISTNAME=	indent-2.2.8a
PKGNAME=	g${DISTNAME:S/a/.1/}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://home.hccnet.nl/d.ingamells/
#MASTER_SITES=	${MASTER_SITE_GNU:=indent/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/indent/indent.html
COMMENT=	GNU version of pretty-printer for C source code

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=	GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=	GNU_PROGRAM_PREFIX

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
