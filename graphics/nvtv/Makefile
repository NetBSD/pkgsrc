# $NetBSD: Makefile,v 1.21.2.1 2012/10/03 12:08:10 spz Exp $

DISTNAME=	nvtv-0.4.7
PKGREVISION=	18
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nv-tv-out/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/nv-tv-out/
COMMENT=	Tool to manipulate TV-Out settings on NVidia cards

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	*-*-i386

CONFLICTS=	nvtv-gtk2-[0-9]*

GNU_CONFIGURE=		YES
RCD_SCRIPTS=		nvtvd

INSTALLATION_DIRS+= share/doc/nvtv

post-patch:
	${CP} ${WRKSRC}/man/nvtv.1x ${WRKSRC}/man/nvtv.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ ${WRKSRC}/doc/USAGE \
		${WRKSRC}/doc/chips.txt \
		${WRKSRC}/doc/overview.txt ${WRKSRC}/doc/timing.txt \
		${DESTDIR}${PREFIX}/share/doc/nvtv

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
