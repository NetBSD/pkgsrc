# $NetBSD: Makefile,v 1.21 2008/03/15 13:10:37 obache Exp $
#

DISTNAME=	paranormal-0.2.0
PKGNAME=	xmms-paranormal-0.2.0
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=paranormal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://paranormal.sourceforge.net/
COMMENT=	Extremely customizable (pseudo-programmable) XMMS plugin

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

# Might be better in textproc/libxml2/buildlink.mk:
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2/libxml

.include "../../devel/SDL/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
