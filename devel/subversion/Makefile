# $NetBSD: Makefile,v 1.5 2002/11/25 20:09:50 wiz Exp $

DISTNAME=	subversion-r3687
PKGNAME=	subversion-0.3687
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/1698/

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://subversion.tigris.org
COMMENT=	Version control system, meant to replace CVS

DEPENDS+=	python22-[0-9]*:../../lang/python22

AUTOCONF_REQD=	2.56
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

post-extract:
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
