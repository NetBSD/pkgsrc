# $NetBSD: Makefile,v 1.1.1.1 2002/05/31 13:20:58 skrll Exp $

DISTNAME=	kdeedu-3.0.1
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

REPLACE_PERL=	\
	${WRKSRC}/kvoctrain/kvoctrain/langen2kvtml \
	${WRKSRC}/kvoctrain/kvoctrain/spotlight2kvtml

USE_BUILDLINK_ONLY=	YES

.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
