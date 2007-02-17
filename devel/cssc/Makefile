# $NetBSD: Makefile,v 1.26 2007/02/17 20:59:47 wiz Exp $
#

DISTNAME=	CSSC-1.0.1
PKGNAME=	cssc-1.0.1
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-binary
CONFIGURE_ENV+=	CONFIG_DIFF_COMMAND=${TOOLS_DIFF:Q}
USE_TOOLS+=	diff makeinfo
TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	# PLIST

.include "../../mk/bsd.pkg.mk"
