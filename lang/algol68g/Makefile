# $NetBSD: Makefile,v 1.2 2011/12/17 10:15:48 sbd Exp $
#

DISTNAME=	algol68g-2.3.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	olafs@cs.ru.nl
HOMEPAGE=	http://jmvdveer.home.xs4all.nl/algol.html
COMMENT=	Algol 68genie compiler
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "options.mk"

.include "../../math/gsl/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
