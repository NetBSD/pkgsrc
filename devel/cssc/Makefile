# $NetBSD: Makefile,v 1.18 2005/04/11 21:45:19 tv Exp $
#

DISTNAME=	CSSC-1.0.1
PKGNAME=	cssc-1.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary
TEST_TARGET=	check

USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		cssc.info

.include "../../mk/bsd.pkg.mk"
