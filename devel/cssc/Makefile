# $NetBSD: Makefile,v 1.21 2005/12/05 20:50:02 rillig Exp $
#

DISTNAME=	CSSC-1.0.1
PKGNAME=	cssc-1.0.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-binary
CONFIGURE_ENV+=	CONFIG_DIFF_COMMAND=${TOOLS_DIFF:Q}
USE_TOOLS+=	diff
TEST_TARGET=	check

USE_MAKEINFO=	YES
TEXINFO_REQD=	4.0
INFO_FILES=	cssc.info

.include "../../mk/bsd.pkg.mk"
