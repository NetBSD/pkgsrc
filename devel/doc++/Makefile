# $NetBSD: Makefile,v 1.4 2003/01/10 07:37:19 cjep Exp $

DISTNAME=		doc++-3.4.9
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docpp/}

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://docpp.sourceforge.net/
COMMENT=		documentation system for C, C++ and Java

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/doc++
	${INSTALL_DATA} ${WRKSRC}/doc/manual/html/* ${PREFIX}/share/doc/doc++

.include "../../mk/bsd.pkg.mk"
