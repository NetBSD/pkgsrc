# $NetBSD: Makefile,v 1.7 2004/01/24 15:06:58 grant Exp $
#

DISTNAME=		pv-0.4.5
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ivarch.com/programs/sources/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=		socrtp@soclab.eu.org
HOMEPAGE=		http://www.ivarch.com/programs/pv.shtml
COMMENT=		Monitor the progress of data through a pipeline

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		pv.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pv
.for i in ../README index.html manual.html quickref.txt lsm NEWS TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/pv
.endfor

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
