# $NetBSD: Makefile,v 1.6 2001/05/23 21:06:01 jlam Exp $

DISTNAME=	nxtvepg-0.5.0
CATEGORIES=	misc
MASTER_SITES=	http://www.nefkom.net/tomzo/prj/nxtvepg/src/

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://nxtvepg.tripod.com/
COMMENT=	NextView EPG decoder

DEPENDS+=	tk>=8.3.2:../../x11/tk

ONLY_FOR_PLATFORM=      NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-* \
			NetBSD-1.5_ALPHA-* NetBSD-1.[5-9]*-*

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL

USE_X11BASE=	yes
USE_PERL5=	yes
USE_GMAKE=	yes

MAKE_ENV+=	X11PREFIX=${X11PREFIX}

pre-configure:
	cd ${WRKSRC};							\
	${MV} -f pod2help.pl pod2help.pl.orig;				\
	${SED} -e "s|@PERL5@|${PERL5}|g" pod2help.pl.orig > pod2help.pl; \
	${CHMOD} +x ${WRKSRC}/pod2help.pl

.include "../../mk/bsd.pkg.mk"
