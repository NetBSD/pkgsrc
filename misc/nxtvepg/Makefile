# $NetBSD: Makefile,v 1.1.1.1 2001/02/18 19:17:24 tron Exp $

DISTNAME=	nxtvepg-0.4.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}

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

pre-configure:
	@${SED} -e 's|@localbase@|'${LOCALBASE}/bin'|' < ${WRKSRC}/pod2help.pl > ${WRKSRC}/pod2help.pl.new && \
		${MV} ${WRKSRC}/pod2help.pl.new ${WRKSRC}/pod2help.pl && \
		${CHMOD} +x ${WRKSRC}/pod2help.pl

.include "../../mk/bsd.pkg.mk"