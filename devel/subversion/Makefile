# $NetBSD: Makefile,v 1.4 2002/11/09 15:18:31 wiz Exp $

DISTNAME=	subversion-r2667
PKGNAME=	subversion-0.2667
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/578/

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://subversion.tigris.org
COMMENT=	Version control system, meant to replace CVS

DEPENDS+=	python22-[0-9]*:../../lang/python22

AUTOCONF_REQD=	2.50
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl
CONFIGURE_ARGS+= --with-berkeley-db=${BUILDLINK_PREFIX.db4}/include/db4:${LOCALBASE}
CONFIGURE_ARGS+= --with-neon=${BUILDLINK_PREFIX.neon}
CONFIGURE_ARGS+= --with-apr=${BUILDLINK_PREFIX.apr}
CONFIGURE_ARGS+= --with-apr-util=${BUILDLINK_PREFIX.apr}
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

PLIST_SUBST+=   INSTALL_INFO=${INSTALL_INFO}
INFO_FILES+=	svn-design.info
INFO_FILES+=	svn-handbook.info

post-extract:
	@${SED} 's/ldb/ldb4/g' < ${WRKSRC}/configure > ${WRKSRC}/configure
	@${RM} -r ${WRKSRC}/neon
	@${RM} -r ${WRKSRC}/apr
	@${RM} -r ${WRKSRC}/apr-util

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/apr-devel/buildlink2.mk"
.include "../../www/neon/buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
