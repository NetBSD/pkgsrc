# $NetBSD: Makefile,v 1.15 2006/01/22 22:16:25 schwarz Exp $

DISTNAME=		doc++-3.4.10
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docpp/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://docpp.sourceforge.net/
COMMENT=		Documentation system for C, C++ and Java

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
BUILD_USES_MSGFMT=	yes

#post-extract:
#	${RM} ${WRKSRC}/src/getopt.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/doc++
	${INSTALL_DATA} ${WRKSRC}/doc/manual/html/* ${PREFIX}/share/doc/doc++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
