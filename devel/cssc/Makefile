# $NetBSD: Makefile,v 1.6 2003/05/30 23:51:25 seb Exp $
#

DISTNAME=	CSSC-0.15alpha.pl0
PKGNAME=	cssc-0.15a.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary
TEXINFO_REQD=		4.0
TEST_TARGET=		check

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
