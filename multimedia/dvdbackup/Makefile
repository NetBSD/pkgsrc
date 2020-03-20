# $NetBSD: Makefile,v 1.12 2020/03/20 11:58:03 nia Exp $

DISTNAME=	dvdbackup-0.4.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dvdbackup/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dvdbackup.sourceforge.net/
COMMENT=	DVD backup utility
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
