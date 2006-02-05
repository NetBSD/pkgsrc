# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:10 joerg Exp $

DISTNAME=		ko-x11fonts-20010722
PKGREVISION=		1
CATEGORIES=		fonts x11 korean
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Korean X11 fonts

DEPENDS+=		ko-baekmuk>=20010718:../../fonts/ko-baekmuk
DEPENDS+=		ko-hanyang>=20010718:../../fonts/ko-hanyang
DEPENDS+=		ko-kaist>=20010718:../../fonts/ko-kaist
DEPENDS+=		ko-mizi>=20010718:../../fonts/ko-mizi

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
