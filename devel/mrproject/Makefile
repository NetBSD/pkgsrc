# $NetBSD: Makefile,v 1.3 2002/07/12 23:03:57 mycroft Exp $
#

DISTNAME=		mrproject-0.5.1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://mrproject.codefactory.se/
COMMENT=		Project management program

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc/mrproject
CONFIGURE_ARGS+=	--without-python

CFLAGS+=		-I${BUILDLINK_DIR}/include/gconf/1
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

DEPENDS+=		skill-[0-9]*:../../sysutils/skill

post-extract:
	# This is an ugly hack to fix the missing file error in 0.5.1
	${TOUCH} ${WRKSRC}/libmrproject/Composer.h

post-patch:
	cd ${WRKSRC}/client/components &&				\
	for f in `${FIND} ${WRKSRC} -name '*.oaf' -print`; do		\
		${MV} $$f $$f.pre &&					\
		${SED} -e 's|/opt/gnome|${PREFIX}|g' $$f.pre > $$f;	\
	done

.include "../../devel/GConf/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../sysutils/gnome-vfs/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
