# $NetBSD: Makefile,v 1.22 2013/11/24 02:38:58 dholland Exp $

DISTNAME=	mono-basic-2.10
PKGREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mono-basic/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Visual Basic .NET support for mono
LICENSE=	gnu-lgpl-v2 AND mit

USE_TOOLS+=		gmake
USE_LANGUAGES+=		# empty
EXTRACT_USING=		gtar
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
SUBST_SED.fix-mandir=		-e 's,share/man,man,'

.include "../../lang/mono2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
