# $NetBSD: Makefile,v 1.1.1.1 2009/08/27 22:50:16 ahoka Exp $
#
DISTNAME=	milkytracker-0.90.80
CATEGORIES=	audio
MASTER_SITES=	http://www.milkytracker.net/files/ \
		${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.milkytracker.net/files/
COMMENT=	Music tracker inspired by Fast Tracker 2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gawk

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

INSTALLATION_DIRS+=	share/doc/milkytracker
INSTALLATION_DIRS+=	share/examples/milkytracker

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/milkytracker

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
