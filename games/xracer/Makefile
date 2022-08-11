# $NetBSD: Makefile,v 1.72 2022/08/11 05:08:37 gutteridge Exp $
#

DISTNAME=		xracer-0.96.9
PKGREVISION=		28
CATEGORIES=		games x11
MASTER_SITES=		http://www.annexia.org/_file/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.annexia.org/freeware/xracer
COMMENT=		XRacer is a clone of the popular Psygnosis game Wipeout

USE_TOOLS+=		gmake perl:run
PERL5_PACKLIST=		auto/XRacer/.packlist

MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes
# disabled by patch-an, since the only existing translation is empty
# and made trouble in 2.1 bulk builds
#USE_TOOLS+=		msgfmt
#USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/XRacer
REPLACE_PERL+=		tools/blender2track/xracer-blender2track.pl \
			tools/mktube/xracer-mktube.pl \
			tools/mktrack/xracer-mktrack.pl \
			tools/mktrackscenery/xracer-mktrackscenery.pl \
			tools/mkcraft/xracer-mkcraft.pl \
			tools/mkmeshnotex/xracer-mkmeshnotex.pl

post-configure: do-makemaker-configure

DEPENDS+=		netpbm-[0-9]*:../../graphics/netpbm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
