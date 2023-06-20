# $NetBSD: Makefile,v 1.74 2023/06/20 18:12:00 wiz Exp $

READLINE_VERSION=	8.2
PKGREVISION=		2

DISTNAME=	readline-${READLINE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tiswww.case.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

PKGCONFIG_OVERRIDE+=	history.pc.in
PKGCONFIG_OVERRIDE+=	readline.pc.in

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV.NetBSD+=	bash_cv_wcwidth_broken=no
.endif

BUILD_TARGET=		everything-libtool
INSTALL_TARGET=		install-libtool install-pc

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
