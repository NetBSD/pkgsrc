# $NetBSD: Makefile,v 1.16 2008/08/02 11:35:41 bjs Exp $
#

DISTNAME=		fribidi-0.10.9
CATEGORIES=		converters
MASTER_SITES=		http://fribidi.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fribidi.org/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	run.tests

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	fribidi.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
