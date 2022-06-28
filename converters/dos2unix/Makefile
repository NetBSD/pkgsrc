# $NetBSD: Makefile,v 1.37 2022/06/28 11:31:08 wiz Exp $

DISTNAME=	dos2unix-7.4.3
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dos2unix/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://waterlan.home.xs4all.nl/dos2unix.html
COMMENT=	DOS/Mac to Unix and vice versa text file format converter
LICENSE=	2-clause-bsd

CONFLICTS=	unix2dos-[0-9]*

USE_TOOLS+=	gmake msgfmt xgettext perl

BUILD_MAKE_FLAGS+=	LDFLAGS_EXTRA+="-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lintl ${LDFLAGS}"
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
