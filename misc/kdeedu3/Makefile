# $NetBSD: Makefile,v 1.12 2003/05/22 02:57:12 markd Exp $

DISTNAME=	kdeedu-3.1.2
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

REPLACE_PERL=	\
	kvoctrain/kvoctrain/langen2kvtml \
	kvoctrain/kvoctrain/spotlight2kvtml

USE_BUILDLINK2=		YES

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
