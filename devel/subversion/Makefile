# $NetBSD: Makefile,v 1.3 2002/10/03 02:44:49 wiz Exp $

DISTNAME=	subversion-r2667
PKGNAME=	subversion-0.2667
CATEGORIES=	devel
MASTER_SITES=	http://subversion.tigris.org/files/documents/15/578/

MAINTAINER=	joelw@unix.se
HOMEPAGE=	http://subversion.tigris.org
COMMENT=	Version control system, meant to replace CVS

DEPENDS=	db4>=4.0.14:../../databases/db4
DEPENDS+=	neon>=0.21.3:../../www/neon
DEPENDS+=	apr-[0-9]*:../../devel/apr-devel
DEPENDS+=	python22-[0-9]*:../../lang/python22

AUTOCONF_REQD=	2.50
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ssl
CONFIGURE_ARGS+= --with-berkeley-db=${LOCALBASE}/include/db4:${LOCALBASE}
CONFIGURE_ARGS+= --with-neon=${LOCALBASE}
CONFIGURE_ARGS+= --with-apr=${LOCALBASE}
CONFIGURE_ARGS+= --with-apr-util=${LOCALBASE}
USE_LIBTOOL=	YES

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

.include "../../mk/autoconf.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
