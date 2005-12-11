# $NetBSD: Makefile,v 1.16 2005/12/11 09:40:38 wiz Exp $
#

DISTNAME=	paranormal-0.2.0
PKGNAME=	xmms-paranormal-0.2.0
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/paranormal/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://paranormal.sourceforge.net/
COMMENT=	Extremely customizable (pseudo-programmable) XMMS plugin

GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=	yes
CPPFLAGS+=	-D_POSIX_THREAD_SYSCALL_SOFT=1

# Might be better in textproc/libxml2/buildlink.mk:
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2
CPPFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2/libxml

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
