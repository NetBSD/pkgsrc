# $NetBSD: Makefile,v 1.15 2009/12/28 09:17:44 obache Exp $
#
DISTNAME=	libFoundation-1.1.7-r168
PKGNAME=	${DISTNAME:S/-r/./}
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.opengroupware.org/nightly/sources/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opengroupware.org/en/devs/thirdparty/libFoundation/
COMMENT=	Library implementing the OpenStep Foundation API
LICENSE=	libFoundation-license

.include	"common.mk"

MAKE_FLAGS=	GNUSTEP_TARGET_DIR="${WRKSRC}/Foundation"

SUBST_FILES.gnustep_installation_dir+=	Foundation/GNUmakefile.postamble
SUBST_FILES.gnustep_installation_dir+=	Foundation/GNUmakefile
SUBST_FILES.gnustep_installation_dir+=	Resources/GNUmakefile

LIBF_HOST_OS=	${GNUSTEP_HOST:C/.*-//}

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${GNUSTEP_HOST_CPU:Q}
PLIST_SUBST+=	LIBF_HOST_OS=${LIBF_HOST_OS}

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-objc-lf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-configure:
	${MKDIR} ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}
	[ -e ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}/${LIBF_HOST_OS} ] || \
	  ${LN} -s							\
	    ${WRKSRC}/Foundation/${LIBF_HOST_OS}	\
	    ${WRKSRC}/Foundation/${GNUSTEP_HOST_CPU}/${LIBF_HOST_OS}

pre-install:
	${MKDIR} ${DESTDIR}${GNUSTEP_MAKEFILES}/Additional

.include "../../mk/bsd.pkg.mk"
