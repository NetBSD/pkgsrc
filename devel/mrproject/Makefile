# $NetBSD: Makefile,v 1.9.2.1 2003/03/07 00:12:13 grant Exp $
#

DISTNAME=		mrproject-0.5.1
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.codefactory.se/pub/software/mrproject/source/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://mrproject.codefactory.se/
COMMENT=		Project management program

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${LOCALBASE}/etc/mrproject
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-evolution-idldir

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

.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/gal/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/oaf/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
#.include "../../mail/evolution/buildlink2.mk"
.include "../../sysutils/gnome-vfs/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
