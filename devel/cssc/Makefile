# $NetBSD: Makefile,v 1.15 2004/10/18 18:49:39 seb Exp $
#

DISTNAME=	CSSC-1.00
PKGNAME=	cssc-1.00
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary
USE_BUILDLINK3=	YES
USE_GCC_SHLIB=	YES
TEST_TARGET=	check

USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		cssc.info

.include "../../mk/bsd.pkg.mk"
