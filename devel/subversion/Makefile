# $NetBSD: Makefile,v 1.7 2003/01/30 17:48:54 drochner Exp $

DISTNAME=	subversion-r4503
PKGNAME=	subversion-0.17.1
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/2699/

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://subversion.tigris.org
COMMENT=	Version control system, meant to replace CVS

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl
CONFIGURE_ARGS+= --with-berkeley-db=${BUILDLINK_PREFIX.db4}/include/db4:${LOCALBASE}
CONFIGURE_ARGS+= --with-neon=${BUILDLINK_PREFIX.neon}
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
BUILDLINK_DEPENDS.apache=	apache>=2.0.44

PLIST_SUBST+=   INSTALL_INFO=${INSTALL_INFO}
INFO_FILES+=	svn-design.info

post-extract:
	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

.include "../../databases/db4/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
