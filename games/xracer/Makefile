# $NetBSD: Makefile,v 1.21 2001/11/29 19:46:11 jlam Exp $
#

DISTNAME=		xracer-0.96.9
CATEGORIES=		games x11
MASTER_SITES=		http://xracer.annexia.org/files/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://xracer.annexia.org/
COMMENT=		XRacer is a clone of the popular Psygnosis game Wipeout

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK_ONLY=	# defined
USE_GMAKE=		# defined
USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XRacer/.packlist

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/automake --gnu --no-force && ${LOCALBASE}/bin/autoconf

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

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
