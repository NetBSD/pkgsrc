# $NetBSD: Makefile,v 1.40 2020/11/05 09:08:17 ryoon Exp $
#

DISTNAME=		Cenon-3.9.6
PKGREVISION=		19
CATEGORIES=		graphics cad gnustep
MASTER_SITES=		http://www.vhf-group.com/vhfInterservice/download/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.cenon.info/
COMMENT=		Vector graphics / CAD / DTP program
LICENSE=		vhf-public-license

USE_LANGUAGES=		objc

WRKSRC=			${WRKDIR}/Cenon
NO_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/Cenon
INSTALLATION_DIRS+=	share/GNUstep/Library/Cenon

FIX_GNUSTEP_INSTALLATION_DIR=		yes
SUBST_FILES.gnustep_installation_dir+=	GNUmakefile
SUBST_FILES.gnustep_installation_dir+=	GNUmakefile.postamble

post-install:
.for doc in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/Cenon
.endfor

.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
