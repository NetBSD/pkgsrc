# $NetBSD: Makefile,v 1.3 2006/01/12 00:44:44 rillig Exp $
#

DISTNAME=		cqual-0.991
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cqual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cqual.sourceforge.net/
COMMENT=		Tool for adding type qualifiers to C

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run

REPLACE_PERL+=		bin/*

INSTALLATION_DIRS=	share/doc/cqual share/examples/cqual

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/doc/user-guide.pdf ${PREFIX:Q}/share/doc/cqual/
	${INSTALL_DATA} ${WRKSRC:Q}/examples/* ${PREFIX:Q}/share/examples/cqual/

.include "../../mk/bsd.pkg.mk"
