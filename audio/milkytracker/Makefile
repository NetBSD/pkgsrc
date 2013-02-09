# $NetBSD: Makefile,v 1.5 2013/02/09 22:11:33 ryoon Exp $
#
DISTNAME=	milkytracker-0.90.80
PKGREVISION=	1
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
