# $NetBSD: Makefile,v 1.4 2000/08/11 20:01:19 jlam Exp $

DISTNAME=		xpuyopuyo-0.9.1
CATEGORIES=		games x11
MASTER_SITES=		http://chaos2.org/xpuyopuyo/ \
			http://lenin.dabney.caltech.edu./~justins/xpuyopuyo/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://chaos2.org/xpuyopuyo/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		libmikmod>=3.1.9:../../audio/libmikmod
DEPENDS+=		xpm-*:../../graphics/xpm

USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-gnome	# install desktop and pixmap files
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG="${GNOME_CONFIG}"

GNOME_CONFIG=		${WRKDIR}/gnome-config

pre-configure:
	cd ${WRKSRC} && autoreconf
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/gnome-config \
		> ${GNOME_CONFIG}
	${CHMOD} +x ${GNOME_CONFIG}

.include "../../mk/bsd.pkg.mk"
