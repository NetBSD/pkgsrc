# $NetBSD: Makefile,v 1.16 2002/10/03 00:30:17 wiz Exp $

DISTNAME=		xpuyopuyo-0.9.1
CATEGORIES=		games x11
MASTER_SITES=		http://chaos2.org/xpuyopuyo/ \
			http://lenin.dabney.caltech.edu./~justins/xpuyopuyo/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://chaos2.org/xpuyopuyo/
COMMENT=		Tetris-like puzzle game

DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		libmikmod>=3.1.9:../../audio/libmikmod

AUTOMAKE_REQD=		1.4
USE_GMAKE=		YES
USE_X11BASE=		YES
USE_XPM=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gnome	# install desktop and pixmap files
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG="${GNOME_CONFIG}"

GNOME_CONFIG=		${WRKDIR}/gnome-config

pre-configure:
	cd ${WRKSRC} && ${AUTOHEADER} && ${AUTOMAKE} --gnu && \
		${AUTORECONF} --force
	${SED} -e "s,@PREFIX@,${PREFIX},g" ${FILESDIR}/gnome-config \
		> ${GNOME_CONFIG}
	${CHMOD} +x ${GNOME_CONFIG}

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
