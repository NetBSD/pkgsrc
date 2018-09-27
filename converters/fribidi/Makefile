# $NetBSD: Makefile,v 1.24 2018/09/27 17:15:25 jklos Exp $

DISTNAME=		fribidi-0.19.7
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=fribidi/}
LICENSE=		gnu-gpl-v2
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/fribidi/fribidi
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	run.tests

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE=	fribidi.pc.in

TEST_TARGET=		check

# avoid installing empty man pages
# (makemandb reports errors for them, and they have no use)
# https://bugs.freedesktop.org/show_bug.cgi?id=67714

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3 && \
		rm fribidi_set_debug.3 fribidi_unicode_version.3 fribidi_version_info.3

.include "../../mk/bsd.pkg.mk"
