# $NetBSD: Makefile,v 1.5 2025/06/02 16:49:07 vins Exp $

DISTNAME=	bwm-ng-0.6.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://www.gropp.org/bwm-ng/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.gropp.org/bwm-ng/
COMMENT=	Console-based bandwidth monitor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		autoconf automake autoreconf

GNU_CONFIGURE=		yes

EGDIR=		share/examples/${PKGBASE}
CONF_FILES=	${PREFIX}/${EGDIR}/bwm-ng.conf-example \
		${PKG_SYSCONFDIR}/bwm-ng.conf

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Adding PKG_SYSCONFDIR support.
SUBST_FILES.conf+=	bwm-ng.1 src/options.c
SUBST_SED.conf=		-e "s:/etc/bwm-ng.conf:${PKG_SYSCONFDIR}/bwm-ng.conf:g"

INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	${RUN} set -e; cd ${WRKSRC} && autoreconf -fiv

post-install:
.for i in bwm-ng.conf-example bwm-ng.css
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
