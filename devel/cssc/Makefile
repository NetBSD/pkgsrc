# $NetBSD: Makefile,v 1.38 2022/10/22 21:34:00 nros Exp $
#

DISTNAME=	CSSC-1.4.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GNU:=cssc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/cssc/
COMMENT=	GNU workalike for the source code control system SCCS
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++11
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-binary
CONFIGURE_ENV+=		CONFIG_DIFF_COMMAND=${TOOLS_DIFF:Q}
USE_TOOLS+=		diff makeinfo
TEST_TARGET=		check

TEXINFO_REQD=	4.0
INFO_FILES=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
