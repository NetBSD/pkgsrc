# $NetBSD: Makefile,v 1.2 2002/07/17 07:54:09 skrll Exp $

DISTNAME=	kdeedu-3.0.2
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
