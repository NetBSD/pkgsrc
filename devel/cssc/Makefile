# $NetBSD: Makefile,v 1.13 2004/01/12 18:34:57 seb Exp $
#

DISTNAME=	CSSC-0.16alpha.pl0
PKGNAME=	cssc-0.16a.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary
USE_BUILDLINK2=	YES
USE_GCC_SHLIB=	YES
TEST_TARGET=	check

USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		cssc.info

.include "../../mk/bsd.pkg.mk"
