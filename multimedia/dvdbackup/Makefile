# $NetBSD: Makefile,v 1.15 2021/05/15 06:48:04 nia Exp $

DISTNAME=	dvdbackup-0.4.2
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdbackup/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdbackup.sourceforge.net/
COMMENT=	DVD backup utility
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes

USE_TOOLS+=	msgfmt msgmerge xgettext

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
