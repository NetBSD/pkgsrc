# $NetBSD: Makefile,v 1.6 2014/01/02 06:45:47 dholland Exp $
#
DISTNAME=	milkytracker-0.90.80
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://milkytracker.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jkuittinen@users.sourceforge.net
HOMEPAGE=	http://milkytracker.org/
COMMENT=	Music tracker inspired by Fast Tracker 2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gawk

.include "options.mk"

INSTALLATION_DIRS+=	share/doc/milkytracker
INSTALLATION_DIRS+=	share/examples/milkytracker

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/milkytracker

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
