# $NetBSD: Makefile,v 1.23 2018/04/14 07:34:00 adam Exp $

DISTNAME=	mono-nat-1.0.2
PKGREVISION=	19
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/22/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	https://github.com/mono/Mono.Nat
COMMENT=	C\# library for uPnP management

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake pkg-config

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	post-patch
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure Mono.Nat/Makefile.in
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
