# $NetBSD: Makefile,v 1.21 2003/01/04 18:25:10 cjep Exp $

DISTNAME=	nxtvepg-2.4.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nxtvepg/}

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://sourceforge.net/projects/nxtvepg/
COMMENT=	NextView EPG decoder

ONLY_FOR_PLATFORM=      NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

USE_PERL5=	yes
USE_GMAKE=	yes
USE_X11=	yes
USE_X11BASE=	yes
USE_BUILDLINK2= yes
pre-configure:
	cd ${WRKSRC};							\
	${MV} -f pod2help.pl pod2help.pl.orig;				\
	${SED} -e "s|@PERL5@|${PERL5}|g" pod2help.pl.orig > pod2help.pl; \
	${CHMOD} +x ${WRKSRC}/pod2help.pl

#pre-build:
#	cd ${WRKSRC};							\
#	${GMAKE} depend

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
