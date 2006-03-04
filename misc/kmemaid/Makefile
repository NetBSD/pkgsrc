# $NetBSD: Makefile,v 1.4 2006/03/04 21:30:11 jlam Exp $
#

DISTNAME=		kmemaid-0.4.7.0
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=memaid/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://memaid.sourceforge.net/
COMMENT=		MemAid flash card program (KDE interface)

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ENV+=		kde_appsdir=${PREFIX:Q}/share/kde/applnk
CONFIGURE_ENV+=		kde_datadir=${PREFIX:Q}/share/kde/apps
CONFIGURE_ENV+=		kde_htmldir=${PREFIX:Q}/share/doc/kde/HTML
CONFIGURE_ENV+=		kde_icondir=${PREFIX:Q}/share/kde/icons

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
