# $NetBSD: Makefile,v 1.1.1.1 2005/01/25 12:19:17 markd Exp $
#

DISTNAME=		kscope-1.0
PKGREVISION=		1
CATEGORIES=		devel kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kscope/}

MAINTAINER=		martijn.van.buul@gmail.com
HOMEPAGE=		http://kscope.sourceforge.net/
COMMENT=		KDE frontend for cscope

DEPENDS+=		cscope>=15.4:../../devel/cscope
DEPENDS+=		exctags>=5.5.4:../../devel/exctags

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

post-build:
	@${SED} -e "s,@LOCALBASE@,${LOCALBASE},g" \
		${FILESDIR}/kscoperc > ${WRKDIR}/kscoperc

pre-install:
	${INSTALL_DATA} ${WRKDIR}/kscoperc ${KDEDIR}/share/kde/config

.include "../../meta-pkgs/kde3/kde3.mk"

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

