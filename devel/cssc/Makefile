# $NetBSD: Makefile,v 1.30 2012/10/31 11:16:48 asau Exp $
#

DISTNAME=	CSSC-1.3.0
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GNU:=cssc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/cssc/
COMMENT=	GNU workalike for the source code control system SCCS
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-binary
CONFIGURE_ENV+=	CONFIG_DIFF_COMMAND=${TOOLS_DIFF:Q}
USE_TOOLS+=	diff makeinfo
TEST_TARGET=	check

TEXINFO_REQD=	4.0
INFO_FILES=	# PLIST

.include "../../mk/bsd.pkg.mk"
