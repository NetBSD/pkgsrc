# $NetBSD: Makefile,v 1.8 2001/01/04 16:59:05 wiz Exp $
#

DISTNAME=		xracer-0.96.9
CATEGORIES=		games x11
MASTER_SITES=		http://xracer.annexia.org/files/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://xracer.annexia.org/

BUILD_DEPENDS+=		autoreconf:../../devel/autoconf
BUILD_DEPENDS+=		automake:../../devel/automake
DEPENDS+=		jpeg-*:../../graphics/jpeg
BUILD_DEPENDS+=		msgfmt:../../devel/gettext

USE_X11=		# defined
USE_MESA=		# defined
USE_GMAKE=		# defined
USE_PERL5=		# defined
USE_LIBINTL=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XRacer/.packlist

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include
CPPFLAGS+=		-I${X11BASE}/include

pre-configure:
	cd ${WRKSRC} && autoconf && automake --gnu --no-force

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

.include "../../mk/bsd.pkg.mk"
