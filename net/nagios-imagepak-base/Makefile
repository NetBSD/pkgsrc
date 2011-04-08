# $NetBSD: Makefile,v 1.4 2011/04/08 22:38:08 morr Exp $
#

DISTNAME=	imagepak-base
PKGNAME=	nagios-imagepak-base-20030219
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Additional icons for nagios
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	nagios-base>=2.0:../../net/nagios-base

WRKSRC=		${WRKDIR}/base

IMAGE_DIR=	${DESTDIR}${PREFIX}/share/nagios/images/logos

.include "../../mk/bsd.prefs.mk"

do-build:

do-install:
	@@cd ${WRKSRC} && \
	${INSTALL_DATA_DIR} ${IMAGE_DIR} && \
	    for i in aix.gd2 aix.gif aix.jpg aix.png amiga.gd2 amiga.gif \
	    amiga.jpg amiga.png apple.gd2 apple.gif apple.jpg apple.png \
	    beos.gd2 beos.gif beos.jpg beos.png caldera.gd2 caldera.gif \
	    caldera.jpg caldera.png cat1900.gd2 cat2900.gd2 cat5000.gd2 \
	    debian.gd2 debian.gif debian.jpg debian.png \
	    freebsd40.gd2 freebsd40.gif freebsd40.jpg freebsd40.png \
	    hp-printer40.gd2 hp-printer40.gif hp-printer40.jpg \
	    hp-printer40.png hpux.gd2 hpux.gif hpux.jpg hpux.png \
	    irix.gd2 irix.gif irix.jpg irix.png \
	    linux40.gd2 linux40.gif linux40.jpg linux40.png logo.gd2 \
	    mac40.gd2 mac40.gif mac40.jpg mac40.png mandrake.gd2 mandrake.gif \
	    mandrake.jpg mandrake.png \
	    next.gd2 next.gif next.jpg next.png ng-switch40.gd2 \
	    ng-switch40.gif ng-switch40.jpg ng-switch40.png novell40.gd2 \
	    novell40.gif novell40.jpg novell40.png \
	    openbsd.gd2 openbsd.gif openbsd.jpg openbsd.png \
	    redhat.gd2 redhat.gif redhat.jpg redhat.png router40.gd2 \
	    router40.gif router40.jpg router40.png \
	    slackware.gd2 slackware.gif slackware.jpg slackware.png \
	    stampede.gd2 stampede.gif stampede.jpg stampede.png station.gd2 \
	    storm.gd2 storm.gif storm.jpg storm.png sun40.gd2 sun40.gif \
	    sun40.jpg sun40.png sunlogo.gd2 sunlogo.gif sunlogo.jpg \
	    sunlogo.png switch40.gd2 switch40.gif switch40.jpg switch40.png \
	    turbolinux.gd2 turbolinux.gif turbolinux.jpg turbolinux.png \
	    ultrapenguin.gd2 ultrapenguin.gif ultrapenguin.jpg \
	    ultrapenguin.png unicos.gd2 unicos.gif unicos.jpg unicos.png \
	    win40.gd2 win40.gif win40.jpg win40.png \
	    yellowdog.gd2 yellowdog.gif yellowdog.jpg yellowdog.png \
	    ; do \
		${ECHO} ${INSTALL_DATA} $$i ${IMAGE_DIR}/$$i; \
		${INSTALL_DATA} $$i ${IMAGE_DIR}/$$i; \
	done

.include "../../mk/bsd.pkg.mk"
