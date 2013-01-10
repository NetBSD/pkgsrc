# $NetBSD: Makefile,v 1.18 2013/01/10 06:59:55 mef Exp $
#

DISTNAME=		fribidi-0.19.5
CATEGORIES=		converters
MASTER_SITES=		http://fribidi.org/download/
LICENSE=		gnu-gpl-v2
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fribidi.org/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

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
