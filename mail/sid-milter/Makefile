# $NetBSD: Makefile,v 1.7 2016/03/05 11:28:51 jperkin Exp $
#

DISTNAME=	sid-milter-1.0.0
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sid-milter/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://sid-milter.sourceforge.net/
COMMENT=	Open source SPF/SenderID filter software from Sendmail, Inc
LICENSE=	sendmail-open-source-license

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.13.0

USE_BUILTIN.libmilter=	NO
USE_TOOLS+=		gm4
MAKE_ENV+=		M4=${M4:Q}
PTHREAD_OPTS+=		require
RCD_SCRIPTS=		sid-filter

SIDDOC=		${PREFIX}/share/doc/sid-milter

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	pre-build
SUBST_FILES.libs=	sid-filter/Makefile.m4
SUBST_SED.libs=		-e "s|@LMBASE@|${BUILDLINK_PREFIX.libmilter}|g"
SUBST_MESSAGE.libs=	Fixing paths.

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man3 ${PKGMANDIR}/man8

post-extract:
	${CP} ${FILESDIR}/sid-filter.m4 ${WRKSRC}/sid-filter/Makefile.m4

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SIDDOC}
	${INSTALL_LIB} ${WRKSRC}/${SIDWORK}/libmarid/sm-marid.h \
		${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/${SIDWORK}/libar/libar.a \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/${SIDWORK}/libar/ar.0 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/
	${INSTALL_PROGRAM} ${WRKSRC}/${SIDWORK}/sid-filter/sid-filter \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${SIDWORK}/sid-filter/sid-filter.0 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/KNOWNBUGS ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/README-SenderID ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/rfc4406.txt ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/rfc4407.txt ${DESTDIR}${SIDDOC}
	${INSTALL_DATA} ${WRKSRC}/rfc4408.txt ${DESTDIR}${SIDDOC}

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# Has to be below include for bsd.pkg.mk, else substition fails
SIDWORK!=		${ECHO} obj.`${UNAME} -srm | ${TR} \  . | ${TR} \/ -`
