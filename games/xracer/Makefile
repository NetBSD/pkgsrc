# $NetBSD: Makefile,v 1.45 2009/06/12 22:26:30 zafer Exp $
#

DISTNAME=		xracer-0.96.9
PKGREVISION=		7
CATEGORIES=		games x11
MASTER_SITES=		http://www.annexia.org/_file/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://www.annexia.org/freeware/xracer
COMMENT=		XRacer is a clone of the popular Psygnosis game Wipeout

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl:run
PERL5_PACKLIST=		auto/XRacer/.packlist

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
