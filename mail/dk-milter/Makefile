# $NetBSD: Makefile,v 1.3 2005/12/05 20:50:29 rillig Exp $

DISTNAME=	dk-milter-0.3.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dk-milter/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://sendmail.net/dk-milter/
COMMENT=	Open source implementation of DomainKeys for sendmail

BUILDLINK_DEPENDS.libmilter+=	libmilter>=8.13.0

LICENSE=		no-profit
MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dk-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4
USE_PKGINSTALL=		YES

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=	dk-filter/Makefile.m4 libdk/Makefile.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g' \
			-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g' \
			-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g' \
			-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|g'
SUBST_MESSAGE.libs=	"Fixing makefile references."

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

post-build:
	${SED} -e 's|dk-filter|dk-milter|g' \
		${WRKSRC}/dk-filter/dk-filter.8 \
		>${WRKSRC}/dk-filter/dk-milter.8

do-install:
	cd ${WRKSRC}/obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ -` && \
		${INSTALL_PROGRAM} dk-filter/dk-filter ${PREFIX}/sbin/dk-milter
	${INSTALL_MAN} ${WRKSRC}/dk-filter/dk-milter.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/dk-milter

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
