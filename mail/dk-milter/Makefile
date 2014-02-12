# $NetBSD: Makefile,v 1.25 2014/02/12 23:18:06 tron Exp $

DISTNAME=	dk-milter-0.3.0
PKGREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dk-milter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/dk-milter/
COMMENT=	Open source implementation of DomainKeys for sendmail
LICENSE=	sendmail-open-source-license

MAKE_ENV+=		M4=${M4:Q}
RCD_SCRIPTS=		dk-milter
USE_BUILTIN.libmilter=	no
USE_TOOLS+=		gm4 csh:run

REPLACE_CSH=		dk-filter/gentxt.csh

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-configure
SUBST_FILES.libs=	dk-filter/Makefile.m4 libdk/Makefile.m4
SUBST_SED.libs=		-e 's|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g'
SUBST_SED.libs+=	-e 's|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD@|${BUILDLINK_PREFIX.pthread}|g'
SUBST_SED.libs+=	-e 's|@PTHREAD_LDFLAGS@|${PTHREAD_LDFLAGS} ${PTHREAD_LIBS}|g'
SUBST_MESSAGE.libs=	Fixing makefile references.

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/dk-milter

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-DSM_CONF_STDBOOL_H=1
.endif

post-extract:
	${LN} -s FreeBSD ${WRKSRC}/devtools/OS/DragonFly

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./Build)

post-build:
	${SED} -e 's|dk-filter|dk-milter|g' \
		${WRKSRC}/dk-filter/dk-filter.8 \
		>${WRKSRC}/dk-filter/dk-milter.8

do-install:
	cd ${WRKSRC}/obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ -` && \
		${INSTALL_PROGRAM} dk-filter/dk-filter \
			${DESTDIR}${PREFIX}/sbin/dk-milter
	${INSTALL_SCRIPT} ${WRKSRC}/dk-filter/gentxt.csh ${DESTDIR}${PREFIX}/sbin/gentxt.csh
	${INSTALL_MAN} ${WRKSRC}/dk-filter/dk-milter.8 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/FEATURES \
		${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/INSTALL \
		${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS \
		${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/dk-milter
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES \
		${DESTDIR}${PREFIX}/share/doc/dk-milter

.include "options.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
