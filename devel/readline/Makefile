# $NetBSD: Makefile,v 1.63 2016/09/19 09:04:29 wiz Exp $

READLINE_VERSION=	7.0

DISTNAME=       readline-${READLINE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=readline/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cnswww.cns.cwru.edu/php/chet/readline/rltop.html
COMMENT=	GNU library that can recall and edit previous input
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
INFO_FILES=		yes

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV.NetBSD+=	bash_cv_wcwidth_broken=no
.endif

BUILD_TARGET=		all-libtool examples
INSTALL_TARGET=		install-libtool

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
