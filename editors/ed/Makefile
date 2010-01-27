# $NetBSD: Makefile,v 1.12 2010/01/27 18:20:43 joerg Exp $

DISTNAME=		ed-1.1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

INFO_FILES=		# PLIST

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

INSTALL_TARGET=		install install-man

.include "../../mk/bsd.pkg.mk"
