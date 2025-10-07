# $NetBSD: Makefile,v 1.78 2025/10/07 18:20:18 wiz Exp $

DISTNAME=	readline-8.3
PKGREVISION=	1
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

.if ${USE_CROSS_COMPILE:U:tl} == yes
CONFIGURE_ENV.NetBSD+=	bash_cv_wcwidth_broken=no
.endif

BUILD_TARGET=		all-libtool
INSTALL_TARGET=		install-libtool install-pc

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
