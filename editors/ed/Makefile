# $NetBSD: Makefile,v 1.10 2008/04/09 00:38:51 reed Exp $

DISTNAME=		ed-0.9
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor

GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

INFO_FILES=		# PLIST

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

post-install:
	cd ${WRKSRC} && ${MAKE} install-man

.include "../../mk/bsd.pkg.mk"
