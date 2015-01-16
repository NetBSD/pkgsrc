# $NetBSD: Makefile,v 1.2 2015/01/16 10:23:24 wiz Exp $

DISTNAME=	qore-0.8.11
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=   .tar.bz2

MAINTAINER=	nros@users.sourceforge.net
COMMENT=	Qore programming language
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake pax
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	native
FLEX_REQD=	2.5.31

# make AC_CHECK_FUNC find gethost* etc on smartos
# http://sourceforge.net/p/qore/code/6980
.if "${OPSYS}" == "SunOS"
LIBS+=		-lnsl
.endif

PKGCONFIG_OVERRIDE+=	qore.pc.in
REPLACE_QORE=		doxygen/qdx

#This is needed in order to comply the with MIT license and binary distribution
#Install docs
licensedir=		share/doc/qore/license
INSTALLATION_DIRS+=	${licensedir}
post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING.GPL ${DESTDIR}${PREFIX}/${licensedir}
	${INSTALL_DATA} ${WRKSRC}/COPYING.LGPL ${DESTDIR}${PREFIX}/${licensedir}
	${INSTALL_DATA} ${WRKSRC}/COPYING.MIT ${DESTDIR}${PREFIX}/${licensedir}
	${INSTALL_DATA} ${WRKSRC}/README-LICENSE ${DESTDIR}${PREFIX}/${licensedir}
	cd ${WRKSRC}/docs/ && ${PAX} -wr * ${DESTDIR}${PREFIX}/share/doc/qore
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/doc/qore

.include "application.mk"
.include "options.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
