# $NetBSD: Makefile,v 1.1.1.1 2002/12/04 11:56:35 agc Exp $
#

DISTNAME=		pv-0.4.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ivarch.com/programs/sources/

MAINTAINER=		socrtp@soclab.eu.org
HOMEPAGE=		http://www.ivarch.com/programs/pv.shtml
COMMENT=		Monitor the progress of data through a pipeline

BUILD_USES_MSGFMT=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes

INFO_FILES=		pv.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pv
.for i in ../README index.html manual.html quickref.txt lsm NEWS TODO COPYING
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/pv
.endfor

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
