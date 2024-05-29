# $NetBSD: Makefile,v 1.63 2024/05/29 16:33:18 adam Exp $

DISTNAME=	GNUMail-1.4.0
PKGREVISION=	3
CATEGORIES=	mail gnustep
MASTER_SITES=	http://download.savannah.nongnu.org/releases/gnustep-nonfsf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/gnustep-nonfsf/gnumail/
COMMENT=	GNUstep clone of NeXT's Mail.app application
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	objc

NO_CONFIGURE=	yes
MAKE_FILE=	GNUmakefile

# /usr/bin/ld: ./obj/GNUMail.obj/GNUMail_main.m.o: undefined reference to symbol 'objc_lookup_class'
# /usr/bin/ld: /usr/pkg/lib/libobjc.so.4.6: error adding symbols: DSO missing from command line
LDFLAGS.NetBSD+=	-lunwind
MAKE_ENV+=		ADDITIONAL_LDFLAGS=${LDFLAGS:Q}

FIX_GNUSTEP_INSTALLATION_DIR=		yes
.for dir in Account Advanced Clock Colors Compose Face Filtering	\
	Fonts Import MIME PGP Receiving Sending Viewing
SUBST_FILES.gnustep_installation_dir+=	Bundles/${dir}/GNUmakefile
.endfor

.include "../../lang/libunwind/buildlink3.mk"
.include "../../mail/Pantomime/buildlink3.mk"
.include "../../misc/Addresses/buildlink3.mk"
.include "../../x11/gnustep-back/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
