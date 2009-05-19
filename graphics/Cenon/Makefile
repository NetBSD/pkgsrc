# $NetBSD: Makefile,v 1.16 2009/05/19 08:59:16 wiz Exp $
#

DISTNAME=		Cenon-3.83
PKGREVISION=		2
CATEGORIES=		graphics cad gnustep
MASTER_SITES=		http://www.vhf-group.com/vhfInterservice/download/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cenon.info/
COMMENT=		Vector graphics / CAD / DTP program
LICENSE=		vhf-public-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		objc

WRKSRC=			${WRKDIR}/Cenon
NO_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

INSTALLATION_DIRS+=	share/doc/Cenon
INSTALLATION_DIRS+=	share/GNUstep/Library/Cenon

FIX_GNUSTEP_INSTALLATION_DIR= yes
SUBST_FILES.gnustep_installation_dir+=	GNUmakefile
SUBST_FILES.gnustep_installation_dir+=	GNUmakefile.postamble

post-install:
.for doc in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/Cenon
.endfor

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
