# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=		pv-0.4.5
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ivarch.com/programs/sources/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pipeviewer/}

MAINTAINER=		socrtp@soclab.eu.org
HOMEPAGE=		http://www.ivarch.com/programs/pv.shtml
COMMENT=		Monitor the progress of data through a pipeline

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		pv.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pv
.for i in ../README index.html manual.html quickref.txt lsm NEWS TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/pv
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
