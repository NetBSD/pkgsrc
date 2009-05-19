# $NetBSD: Makefile,v 1.2 2009/05/19 08:59:10 wiz Exp $
#
DISTNAME=	libFoundation-1.1.7-r168
PKGNAME=	${DISTNAME:S/-/-examples-/:S/-r/./}
CATEGORIES=	devel gnustep
MASTER_SITES=	http://download.opengroupware.org/nightly/sources/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.opengroupware.org/en/devs/thirdparty/libFoundation/
COMMENT=	Library implementing the OpenStep Foundation API
LICENSE=	libFoundation-license

.include	"../../devel/libFoundation/common.mk"

INSTALL_DIRS=	examples
MAKE_FLAGS=	GNUSTEP_TARGET_DIR="${WRKSRC}/examples"

SUBST_FILES.gnustep_installation_dir+=	examples/GNUmakefile

LIBF_HOST_OS=	${GNUSTEP_HOST:C/.*-//}

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${GNUSTEP_HOST_CPU:Q}
PLIST_SUBST+=	LIBF_HOST_OS=${LIBF_HOST_OS}

pre-build:
	${MKDIR} ${WRKSRC}/examples/GNU

.include "../../devel/libFoundation/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
