# $NetBSD: Makefile,v 1.10 2004/10/03 00:13:11 tv Exp $
#

DISTNAME=	paranormal-0.2.0
PKGNAME=	xmms-paranormal-0.2.0
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/paranormal/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://paranormal.sourceforge.net/
COMMENT=	Extremely customizable (pseudo-programmable) XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=	yes
USE_X11=	yes
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

# Might be better in textproc/libxml2/buildlink.mk:
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2/libxml

USE_BUILDLINK3=	yes

post-extract:
		cd ${WRKSRC} ; \
		if [ ! -f configure.orig ]; then \
			${MV} configure configure.orig ; \
		fi ; \
		${SED} \
			-e 's|XML_CONFIG|XML2_CONFIG|g' \
			<configure.orig >configure ; \
		${CHMOD} +x configure

.include "../../devel/SDL/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
