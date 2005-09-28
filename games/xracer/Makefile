# $NetBSD: Makefile,v 1.37 2005/09/28 20:52:22 rillig Exp $
#

DISTNAME=		xracer-0.96.9
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		http://xracer.annexia.org/files/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://xracer.annexia.org/
COMMENT=		XRacer is a clone of the popular Psygnosis game Wipeout

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		automake14 gmake perl:run
PERL5_PACKLIST=		auto/XRacer/.packlist

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && automake --gnu && autoconf

pre-patch:
.for perlfile in blender2track/xracer-blender2track.pl \
		mktube/xracer-mktube.pl \
		mktrack/xracer-mktrack.pl \
		mktrackscenery/xracer-mktrackscenery.pl \
		mkcraft/xracer-mkcraft.pl \
		mkmeshnotex/xracer-mkmeshnotex.pl
	@${CP} ${WRKSRC}/tools/${perlfile} ${WRKSRC}/tools/${perlfile}.BAK
	@${SED} 's!/usr/bin/perl!${PERL5}!g' \
		< ${WRKSRC}/tools/${perlfile}.BAK > ${WRKSRC}/tools/${perlfile}
	@${RM} ${WRKSRC}/tools/${perlfile}.BAK
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
