# $NetBSD: Makefile,v 1.8 2004/04/24 22:46:09 jlam Exp $

DISTNAME=		doc++-3.4.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docpp/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://docpp.sourceforge.net/
COMMENT=		Documentation system for C, C++ and Java

USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/doc++
	${INSTALL_DATA} ${WRKSRC}/doc/manual/html/* ${PREFIX}/share/doc/doc++

.include "../../mk/bsd.pkg.mk"
