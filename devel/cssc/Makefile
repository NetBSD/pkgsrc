# $NetBSD: Makefile,v 1.10 2003/07/17 21:30:00 grant Exp $
#

DISTNAME=	CSSC-0.15alpha.pl0
PKGNAME=	cssc-0.15a.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary
USE_BUILDLINK2=	YES
TEST_TARGET=	check

USE_NEW_TEXINFO=	YES
USE_MAKEINFO=		YES
TEXINFO_REQD=		4.0
INFO_FILES=		cssc.info

.include "../../mk/bsd.pkg.mk"
