# $NetBSD: Makefile,v 1.22 2004/10/03 00:12:59 tv Exp $

DISTNAME=	kdepim-2.2.2
PKGREVISION=	8
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK3=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/libical/ltconfig

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+= -DSunOS
BUILD_DEPENDS+= bison-[0-9]*:../../devel/bison
YACC= bison -y
.endif

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
