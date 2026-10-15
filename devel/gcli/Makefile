# $NetBSD: Makefile,v 1.15 2026/10/15 21:33:55 tm Exp $

DISTNAME=	gcli-2.13.0
CATEGORIES=	devel
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-2.13.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://herrhotzenplotz.de/gcli/
COMMENT=	Portable CLI tool for interacting with GitHub/Lab/Tea
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config realpath

PKGCONFIG_OVERRIDE+=	libgcli.pc.in

SUBST_CLASSES+=			fix-mandir
SUBST_STAGE.fix-mandir=		pre-configure
SUBST_MESSAGE.fix-mandir=	Fixing man path
SUBST_FILES.fix-mandir=		Makefile.in
SUBST_SED.fix-mandir=		-e 's,share/man,${PKGMANDIR},'

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
