# $NetBSD: Makefile,v 1.48 2023/11/08 13:19:49 wiz Exp $

DISTNAME=	mono-basic-4.7
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	https://download.mono-project.com/sources/mono-basic/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://www.mono-project.com/
COMMENT=	Visual Basic .NET support for mono
LICENSE=	gnu-lgpl-v2 AND mit

USE_TOOLS+=		gmake
USE_LANGUAGES+=		# empty
ALL_ENV+=		PLATFORM=

GNU_CONFIGURE=		yes

REPLACE_SH+=		vbnc/vbnc/setversion.sh

UNLIMIT_RESOURCES=	datasize
UNLIMIT_RESOURCES+=	stacksize
UNLIMIT_RESOURCES+=	memorysize

SUBST_CLASSES+=			fix-mandir
SUBST_STAGE.fix-mandir=		post-configure
SUBST_MESSAGE.fix-mandir=	Fixing man path
SUBST_FILES.fix-mandir=		build/config.make
SUBST_SED.fix-mandir=		-e 's,share/man,${PKGMANDIR},'

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
