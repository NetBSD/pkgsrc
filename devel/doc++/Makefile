# $NetBSD: Makefile,v 1.22 2012/02/16 18:36:34 hans Exp $

DISTNAME=		doc++-3.4.10
PKGREVISION=	3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docpp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://docpp.sourceforge.net/
COMMENT=		Documentation system for C, C++ and Java

USE_TOOLS+=		flex gmake msgfmt
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++

LIBS.SunOS+=		-lintl

INSTALLATION_DIRS+= share/doc/doc++
PKG_DESTDIR_SUPPORT= user-destdir

#post-extract:
#	${RM} ${WRKSRC}/src/getopt.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/manual/html/* ${DESTDIR}${PREFIX}/share/doc/doc++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
