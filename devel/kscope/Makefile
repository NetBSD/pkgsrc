# $NetBSD: Makefile,v 1.9 2006/06/21 13:21:25 joerg Exp $
#

DISTNAME=		kscope-1.3.3
PKGREVISION=		3
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kscope/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://kscope.sourceforge.net/
COMMENT=		KDE frontend for cscope

DEPENDS+=		cscope>=15.4:../../devel/cscope
DEPENDS+=		exctags>=5.5.4:../../devel/exctags

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

post-build:
	@${SED} -e "s,@LOCALBASE@,${LOCALBASE},g" \
		${FILESDIR}/kscoperc > ${WRKDIR}/kscoperc

pre-install:
	${INSTALL_DATA} ${WRKDIR}/kscoperc ${KDEDIR}/share/kde/config

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

