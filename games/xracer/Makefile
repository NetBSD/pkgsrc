# $NetBSD: Makefile,v 1.30 2004/10/03 00:14:47 tv Exp $
#

DISTNAME=		xracer-0.96.9
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		http://xracer.annexia.org/files/

MAINTAINER=		bsieker@freenet.de
HOMEPAGE=		http://xracer.annexia.org/
COMMENT=		XRacer is a clone of the popular Psygnosis game Wipeout

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK3=		yes
USE_X11=		# defined
USE_GNU_TOOLS+=		make
USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XRacer/.packlist

USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
AUTOMAKE_REQD=		1.4

pre-configure:
	cd ${WRKSRC} && ${AUTOMAKE} --gnu && ${AUTOCONF}

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
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
