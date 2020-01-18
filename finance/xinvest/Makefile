# $NetBSD: Makefile,v 1.21 2020/01/18 23:31:00 rillig Exp $

DISTNAME=		xinvest-2.6.9
PKGREVISION=		3
CATEGORIES=		finance x11
MASTER_SITES=		http://sourceforge.net/projects/xinvest/files/latest/download

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xinvest.sourceforge.net/
COMMENT=		Personal finance tracking and performance tool

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
