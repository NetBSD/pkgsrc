# $NetBSD: Makefile,v 1.9 2003/04/15 16:23:22 salo Exp $
#

DISTNAME=	subversion-0.20.1
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/3440/

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://subversion.tigris.org
COMMENT=	Version control system, meant to replace CVS

BUILDLINK_DEPENDS.apache=	apache>=2.0.44
# we need apr shared libs at runtime
BUILDLINK_DEPMETHOD.apache=	full

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS=		--with-ssl
CONFIGURE_ARGS+=	--with-berkeley-db=${BUILDLINK_PREFIX.db4}/include/db4:${LOCALBASE}
CONFIGURE_ARGS+=	--with-neon=${BUILDLINK_PREFIX.neon}

PLIST_SUBST=	INSTALL_INFO=${INSTALL_INFO}
INFO_FILES=	svn-design.info

post-extract:
	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

.include "../../databases/db4/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../www/apache2/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
