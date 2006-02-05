# $NetBSD: Makefile,v 1.14 2006/02/05 23:10:56 joerg Exp $
#

DISTNAME=		pv-0.8.6
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ivarch.com/programs/sources/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ivarch.com/programs/pv.shtml
COMMENT=		Monitor the progress of data through a pipeline

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

INFO_FILES=		pv.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pv
.for i in ../README index.html manual.html quickref.txt lsm NEWS TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/pv
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
