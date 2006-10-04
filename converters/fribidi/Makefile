# $NetBSD: Makefile,v 1.13 2006/10/04 20:52:11 wiz Exp $
#

DISTNAME=		fribidi-0.10.4
PKGREVISION=		1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fribidi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fribidi.org/
COMMENT=		Free Implementation of the Unicode Bidirectional Algorithm

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${SH}
REPLACE_FILES.bash=	run.tests

USE_LIBTOOL=            yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=	fribidi.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
