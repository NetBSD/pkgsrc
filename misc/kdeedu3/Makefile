# $NetBSD: Makefile,v 1.4 2002/10/03 22:26:56 markd Exp $

DISTNAME=	kdeedu-3.0.3
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

REPLACE_PERL=	\
	${WRKSRC}/kvoctrain/kvoctrain/langen2kvtml \
	${WRKSRC}/kvoctrain/kvoctrain/spotlight2kvtml

USE_BUILDLINK2=		YES

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
