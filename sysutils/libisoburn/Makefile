# $NetBSD: Makefile,v 1.6 2020/04/05 12:49:44 nia Exp $

DISTNAME=	libisoburn-1.5.2
#PKGNAME=	${DISTNAME:S/.pl/pl/}
CATEGORIES=	sysutils
MASTER_SITES=	http://files.libburnia-project.org/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://libburnia-project.org/wiki/Libisoburn
COMMENT=	Library to enable creation and expansion of ISO-9660 filesystems
LICENSE=	gnu-gpl-v2

DEPENDS+=	tcl-[0-9]*:../../lang/tcl
DEPENDS+=	tk-[0-9]*:../../x11/tk

WRKSRC=		${WRKDIR}/${DISTNAME:C/.pl[0-9]*//}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
INFO_FILES=	yes

PKGCONFIG_OVERRIDE+=	libisoburn-1.pc.in

SUBST_CLASSES+=		fix-wish
SUBST_STAGE.fix-wish=	pre-configure
SUBST_MESSAGE.fix-wish=	Fixing tcl wish
SUBST_FILES.fix-wish+=	frontend/xorriso-tcltk
SUBST_SED.fix-wish+=	-e 's,/usr/bin/wish,${LOCALBASE}/bin/wish,'

.include "../../converters/libiconv/buildlink3.mk"
.include "../../sysutils/libisofs/buildlink3.mk"
.include "../../sysutils/libburn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
