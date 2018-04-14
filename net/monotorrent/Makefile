# $NetBSD: Makefile,v 1.25 2018/04/14 07:34:00 adam Exp $

DISTNAME=	monotorrent-0.72
PKGREVISION=	19
CATEGORIES=	net
MASTER_SITES=	http://projects.qnetp.net/attachments/download/13/

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://monotorrent.com/
COMMENT=	Open source bittorrent library

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no
USE_TOOLS+=	gmake bsdtar pkg-config
EXTRACT_USING=	bsdtar

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	post-patch
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure MonoTorrent/Makefile.in
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
