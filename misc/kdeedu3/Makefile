# $NetBSD: Makefile,v 1.17 2003/12/08 14:41:40 wiz Exp $

DISTNAME=	kdeedu-3.1.4
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop
PKGREVISION=	1

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_PERL=	\
	kvoctrain/kvoctrain/langen2kvtml \
	kvoctrain/kvoctrain/spotlight2kvtml

USE_BUILDLINK2=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
