# $NetBSD: Makefile,v 1.28 2004/04/24 22:46:10 jlam Exp $

DISTNAME=		xpuyopuyo-0.9.1
PKGREVISION=		4
CATEGORIES=		games x11
MASTER_SITES=		http://chaos2.org/xpuyopuyo/ \
			http://lenin.dabney.caltech.edu./~justins/xpuyopuyo/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://chaos2.org/xpuyopuyo/
COMMENT=		Tetris-like puzzle game

AUTOMAKE_REQD=		1.4
USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11BASE=		YES
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

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
