# $NetBSD: Makefile,v 1.7 2003/12/04 19:48:24 xtraeme Exp $
#

DISTNAME=	paranormal-0.2.0
PKGNAME=	xmms-paranormal-0.2.0
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/paranormal/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://paranormal.sourceforge.net/
COMMENT=	Extremely customizable (pseudo-programmable) XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	YES
USE_X11=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

# Might be better in textproc/libxml2/buildlink.mk:
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2/libxml

USE_BUILDLINK2=	yes

post-extract:
		cd ${WRKSRC} ; \
		if [ ! -f configure.orig ]; then \
			${MV} configure configure.orig ; \
		fi ; \
		${SED} \
			-e 's|XML_CONFIG|XML2_CONFIG|g' \
			<configure.orig >configure ; \
		${CHMOD} +x configure

.include "../../devel/SDL/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
