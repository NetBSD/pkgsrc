# $NetBSD: Makefile,v 1.26 2004/04/25 06:26:43 snj Exp $
#

DISTNAME=		mrproject-0.5.1
PKGREVISION=		13
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://mrproject.codefactory.se/
COMMENT=		Project management program

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc/mrproject
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-evolution-idldir

CFLAGS+=		-I${BUILDLINK_DIR}/include/gconf/1

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

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/gal/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
#.include "../../mail/evolution/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
