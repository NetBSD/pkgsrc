# $NetBSD: Makefile,v 1.3 2000/06/21 08:12:37 jlam Exp $
#

DISTNAME=		xracer-0.96.9
CATEGORIES=		games x11
MASTER_SITES=		http://xracer.annexia.org/files/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://xracer.annexia.org/

DEPENDS+=		Mesa-*:../../graphics/Mesa
DEPENDS+=		jpeg-*:../../graphics/jpeg
DEPENDS+=		gettext-0.10.*:../../devel/gettext

USE_X11=		# defined
USE_GMAKE=		# defined
USE_PERL5=		# defined
PERL=			${LOCALBASE}/bin/perl

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${X11BASE}/include

pre-patch:
.for perlfile in blender2track/xracer-blender2track.pl \
		mktube/xracer-mktube.pl \
		mktrack/xracer-mktrack.pl \
		mktrackscenery/xracer-mktrackscenery.pl \
		mkcraft/xracer-mkcraft.pl \
		mkmeshnotex/xracer-mkmeshnotex.pl
	@${CP} ${WRKSRC}/tools/${perlfile} ${WRKSRC}/tools/${perlfile}.BAK
	@${SED} 's!/usr/bin/perl!${PERL}!g' \
		< ${WRKSRC}/tools/${perlfile}.BAK > ${WRKSRC}/tools/${perlfile}
	@${RM} ${WRKSRC}/tools/${perlfile}.BAK
.endfor

.include "../../mk/bsd.pkg.mk"
