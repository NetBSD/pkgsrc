# $NetBSD: Makefile,v 1.1.1.1 2000/05/29 06:36:00 rh Exp $
#

DISTNAME=	xracer-0.96.9
CATEGORIES=	games x11
MASTER_SITES=	http://xracer.annexia.org/files/

MAINTAINER=	bsieker@freenet.de
HOMEPAGE=	http://xracer.annexia.org/

DEPENDS+=	perl-*:../../lang/perl5
DEPENDS+=	Mesa-*:../../graphics/Mesa
DEPENDS+=	mpeg-*:../../graphics/mpeg-lib
DEPENDS+=	jpeg>=6:../../graphics/jpeg

USE_X11=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib -lintl"

USE_LIBTOOL=    YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

pre-patch:
.for perlfile in blender2track/xracer-blender2track.pl \
		mktube/xracer-mktube.pl \
		mktrack/xracer-mktrack.pl \
		mktrackscenery/xracer-mktrackscenery.pl \
		mkcraft/xracer-mkcraft.pl \
		mkmeshnotex/xracer-mkmeshnotex.pl
	@${CP} ${WRKSRC}/tools/${perlfile} ${WRKSRC}/tools/${perlfile}.BAK
	@${SED} 's!/usr/bin/perl!${LOCALBASE}/bin/perl!g' \
	  < ${WRKSRC}/tools/${perlfile}.BAK > ${WRKSRC}/tools/${perlfile}
	@${RM} ${WRKSRC}/tools/${perlfile}.BAK
.endfor

.include "../../mk/bsd.pkg.mk"
