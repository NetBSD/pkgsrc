# $NetBSD: Makefile,v 1.17 2002/08/31 09:25:04 magick Exp $

DISTNAME=	nxtvepg-2.2.1
CATEGORIES=	misc
MASTER_SITES=	http://www.nefkom.net/tomzo/prj/nxtvepg/src/

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://www.nefkom.net/tomzo/prj/nxtvepg/
COMMENT=	NextView EPG decoder

ONLY_FOR_PLATFORM=      NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

USE_PERL5=	yes
USE_GMAKE=	yes
USE_X11=	yes
USE_BUILDLINK_ONLY= yes
pre-configure:
	cd ${WRKSRC};							\
	${MV} -f pod2help.pl pod2help.pl.orig;				\
	${SED} -e "s|@PERL5@|${PERL5}|g" pod2help.pl.orig > pod2help.pl; \
	${CHMOD} +x ${WRKSRC}/pod2help.pl

pre-build:
	cd ${WRKSRC};							\
	${GMAKE} depend

.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
