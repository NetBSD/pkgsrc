# $NetBSD: Makefile,v 1.24 2004/01/24 13:30:57 grant Exp $

DISTNAME=		xpuyopuyo-0.9.1
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		http://chaos2.org/xpuyopuyo/ \
			http://lenin.dabney.caltech.edu./~justins/xpuyopuyo/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://chaos2.org/xpuyopuyo/
COMMENT=		Tetris-like puzzle game

DEPENDS+=		gnome1-dirs>=1.0:../../misc/gnome1-dirs

AUTOMAKE_REQD=		1.4
USE_BUILDLINK2=		YES
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

.include "../../audio/libmikmod/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
