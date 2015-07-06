# $NetBSD: Makefile,v 1.14 2015/07/06 04:46:10 kefren Exp $

DISTNAME=	mono-nat-1.0.2
PKGREVISION=	12
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/22/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://projects.qnetp.net/projects/show/mono-nat
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
