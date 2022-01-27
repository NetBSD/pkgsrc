# $NetBSD: Makefile,v 1.21 2022/01/27 17:39:45 nros Exp $

DISTNAME=	qore-1.2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=qorelanguage/}
EXTRACT_SUFX=	.tar.bz2

GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	nros@NetBSD.org
COMMENT=	Embeddable multithreaded scripting language
HOMEPAGE=	http://www.qore.org/
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mit
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bash bison flex gmake pax
USE_LANGUAGES=	c c99 c++
PTHREAD_OPTS+=	native
FLEX_REQD=	2.5.31

PKGCONFIG_OVERRIDE+=	qore.pc.in
REPLACE_QORE=		bin/qdbg bin/qdbg-remote bin/qdbg-server
REPLACE_QORE+=		bin/qdbg-vsc-adapter bin/qdp bin/qget
REPLACE_QORE+=		bin/rest bin/saprest bin/schema-reverse
REPLACE_QORE+=		bin/sfrest bin/sqlutil doxygen/qdx doxygen/qjar

CONFIGURE_ARGS+=	--with-libsuffix="" --disable-single-compilation-unit

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
