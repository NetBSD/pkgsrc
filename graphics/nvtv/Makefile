# $NetBSD: Makefile,v 1.41 2018/11/12 03:52:15 ryoon Exp $

DISTNAME=	nvtv-0.4.7
PKGREVISION=	33
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nv-tv-out/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/nv-tv-out/
COMMENT=	Tool to manipulate TV-Out settings on NVidia cards

ONLY_FOR_PLATFORM=	*-*-i386	# uses iopl()
ONLY_FOR_PLATFORM+=	*-*-x86_64	# may not build without some hacking
NOT_FOR_PLATFORM+=	NetBSD-*-x86_64	# lack of x86_64_[gs]_set_ioperm.
CONFLICTS=	nvtv-gtk2-[0-9]*

USE_TOOLS+=		pkg-config
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
