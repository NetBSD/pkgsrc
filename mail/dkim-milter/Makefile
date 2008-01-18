# $NetBSD: Makefile,v 1.10 2008/01/18 05:08:22 tnn Exp $

DISTNAME=	dkim-milter-0.1.1
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dkim-milter/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://sourceforge.net/projects/dkim-milter/
COMMENT=	Open source DKIM filter software from Sendmail, Inc

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0

LICENSE=		sendmail-open-source-license

MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dkim-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=	dkim-filter/Makefile.m4 libdk/Makefile.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g' \
			-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g' \
			-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g' \
			-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|g'
SUBST_MESSAGE.libs=	Fixing makefile references.

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/dkim-milter

post-extract:
	${LN} -s FreeBSD ${WRKSRC}/devtools/OS/DragonFly

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

post-build:
	${SED} -e 's|dkim-filter|dkim-milter|g' \
		${WRKSRC}/dkim-filter/dkim-filter.8 \
		>${WRKSRC}/dkim-filter/dkim-milter.8

do-install:
	cd ${WRKSRC}/obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ -` && \
		${INSTALL_PROGRAM} dkim-filter/dkim-filter ${PREFIX}/sbin/dkim-milter
	${INSTALL_MAN} ${WRKSRC}/dkim-filter/dkim-milter.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dkim-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${PREFIX}/share/doc/dkim-milter

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
