# $NetBSD: Makefile,v 1.11 2002/10/26 13:20:21 bouyer Exp $

DISTNAME=	kdepim-2.2.2
PKGREVISION=	2
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/libical/ltconfig

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+= -DSunOS
BUILD_DEPENDS+= bison:../../devel/bison
YACC= bison -y
.endif


.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
