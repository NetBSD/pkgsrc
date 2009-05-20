# $NetBSD: Makefile,v 1.3 2009/05/20 00:58:22 wiz Exp $

DISTNAME=	units-1.86
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=units/}

MAINTAINER=	cameron@patrick.wattle.id.au
HOMEPAGE=	http://www.gnu.org/software/units/
COMMENT=	GNU Units - a calculator capable of performing unit conversions

PKG_DESTDIR_SUPPORT=	user-destdir

INFO_FILES=	YES

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}

PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
