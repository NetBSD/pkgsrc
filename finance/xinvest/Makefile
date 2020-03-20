# $NetBSD: Makefile,v 1.22 2020/03/20 11:57:38 nia Exp $

DISTNAME=		xinvest-2.6.9
PKGREVISION=		3
CATEGORIES=		finance x11
MASTER_SITES=		http://sourceforge.net/projects/xinvest/files/latest/download

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xinvest.sourceforge.net/
COMMENT=		Personal finance tracking and performance tool

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
