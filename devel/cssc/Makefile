# $NetBSD: Makefile,v 1.1.1.1 2002/01/24 23:44:29 seb Exp $
#

DISTNAME=	CSSC-0.13alpha.pl1a
PKGNAME=	cssc-0.13a.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cssc/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cssc.sourceforge.net/
COMMENT=	GNU workalike for the source code control system SCCS

WRKSRC=	${WRKDIR}/CSSC-0.13alpha.pl1
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-binary

.include "../../mk/bsd.pkg.mk"
