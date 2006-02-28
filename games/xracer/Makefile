# $NetBSD: Makefile,v 1.40 2006/02/28 17:45:55 wiz Exp $
#

DISTNAME=		xracer-0.96.9
PKGREVISION=		6
CATEGORIES=		games x11
MASTER_SITES=		http://xracer.annexia.org/files/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://xracer.annexia.org/
COMMENT=		XRacer is a clone of the popular Psygnosis game Wipeout

USE_TOOLS+=		gmake perl:run
PERL5_PACKLIST=		auto/XRacer/.packlist

USE_LIBTOOL=		yes
# disabled by patch-an, since the only existing translation is empty
# and made trouble in 2.1 bulk builds
#BUILD_USES_MSGFMT=	yes
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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
