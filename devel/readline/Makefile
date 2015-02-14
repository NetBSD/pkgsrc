# $NetBSD: Makefile,v 1.61 2015/02/14 06:51:33 riastradh Exp $

READLINE_VERSION=	6.3

DISTNAME=       readline-${READLINE_VERSION}
PKGREVISION=	3
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
.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		bash_cv_wcwidth_broken=no
.endif
.endif

BUILD_TARGET=		all-libtool examples
INSTALL_TARGET=		install-libtool

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
