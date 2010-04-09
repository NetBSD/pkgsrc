# $NetBSD: Makefile,v 1.10 2010/04/09 15:48:17 kefren Exp $

DISTNAME=	mono-basic-2.6.2
CATEGORIES=	lang
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/mono-basic/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Visual Basic .NET support for mono

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LANGUAGES+=		# empty
EXTRACT_USING=		gtar

GNU_CONFIGURE=		yes

UNLIMIT_RESOURCES=	datasize
UNLIMIT_RESOURCES+=	stacksize
UNLIMIT_RESOURCES+=	memorysize

SUBST_CLASSES+=			fix-mandir
SUBST_STAGE.fix-mandir=		post-configure
SUBST_MESSAGE.fix-mandir=	Fixing man path
SUBST_FILES.fix-mandir=		build/config.make
SUBST_SED.fix-mandir=		-e 's,share/man,man,'

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
