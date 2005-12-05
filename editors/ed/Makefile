# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:09 rillig Exp $

DISTNAME=		ed-0.2
PKGREVISION=		1
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor

GNU_CONFIGURE=		YES
CONFIGURE_HAS_INFODIR=	NO
CONFIGURE_HAS_MANDIR=	NO
MAKE_ENV+=		INFO_DIR=${INFO_DIR:Q}

.include "../../mk/bsd.prefs.mk"

INFO_FILES=		${GNU_PROGRAM_PREFIX}ed.info

.if defined(GNU_PROGRAM_PREFIX)
# the ./configure accepts --program-prefix, but doesn't use
MAKE_ENV+=		binprefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=           GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=            GNU_PROGRAM_PREFIX

.include "../../mk/bsd.pkg.mk"
